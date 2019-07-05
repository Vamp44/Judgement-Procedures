//
//  main.cpp
//  Judgement Procedures.
//
//  Created by s2018 on 2019/6/19.
//  Copyright © 2019 s2018. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

ifstream stu("/Users/nianqingren/Desktop/accurac/JudgementProcedures/student.txt");
ifstream judge("/Users/nianqingren/Desktop/accurac/JudgementProcedures/judge.txt");
ofstream final_s("/Users/nianqingren/Desktop/accurac/JudgementProcedures/final.csv");

const int maxn = 50;
struct student
{
    string school;
    string name_s;
    string stu_num;
    string tel_num;
    double scor[maxn];
    double ave;
}s[maxn];
struct judge
{
    string jug_num;
    string company;
    string name_j;
    double scor[maxn];
}ju[maxn];

bool compare(const student &s1, const student &s2)
{
    return (s1.ave > s2.ave);
}

int main(int argc, const char * argv[]) {
    int n1=0,i=0;
    while(!stu.eof())
    {
        n1++;
        stu >> s[i].school >> s[i].stu_num >> s[i].name_s >>s[i].tel_num;
        i++;
    }
    int n2=0,j=0;
    while(!judge.eof())
    {
        n2++;
        getline(judge,ju[j].company,' ');
        getline(judge,ju[j].jug_num,' ');
        getline(judge,ju[j].name_j,' ');
        for(int i=0; i<n1; i++)
        {
            judge >> ju[j].scor[i];
        }
        j++;
    }
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            s[i].scor[j] = ju[j].scor[i];
        }
    }
    stu.close();
    judge.close();
    for(int i=0; i<n1; i++)
    {
        double sum=0;
        double max=s[i].scor[0],min=s[i].scor[0];
        for(int j=0; j<n2; j++)
        {
            if(s[i].scor[j]>max)
                max=s[i].scor[j];
            if(min>s[i].scor[j])
                min=s[i].scor[j];
            sum+=s[i].scor[j];
        }
        s[i].ave=(sum-min-max)/(n2-2);
    }
    sort(s, s+n1, compare);
    final_s << left << setw(12) <<"排名";
    final_s << left << setw(26) <<"隶属学院";
    final_s << left << setw(23) <<"学号";
    final_s << left << setw(13) <<"姓名";
    final_s << left << setw(18) <<"平均成绩";
    final_s << left << setw(19) <<"联系方式";
    final_s << endl;
    for(int i=0; i<n1; i++)
    {
        if(i<9)
        {
            final_s <<"第"<< i+1 << left << setw(8) <<"名";
            final_s << left << setw(29) << s[i].school ;
            final_s << left << setw(20) << s[i].stu_num ;
            final_s << left << setw(15) << s[i].name_s ;
            final_s << left << setw(11) << s[i].ave ;
            final_s << left << setw(14) << s[i].tel_num ;
            final_s << endl;
        }
        else
        {
            final_s <<"第"<< i+1 << left << setw(7) <<"名";
            final_s << left << setw(29) << s[i].school ;
            final_s << left << setw(20) << s[i].stu_num ;
            final_s << left << setw(15) << s[i].name_s ;
            final_s << left << setw(11) << s[i].ave ;
            final_s << left << setw(14) << s[i].tel_num ;
            final_s << endl;
        }
    }
    final_s.close();
    return 0;
}
