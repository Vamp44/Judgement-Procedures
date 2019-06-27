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

ifstream stu("/Users/nianqingren/Desktop/accurac/student.txt");
ifstream judge("/Users/nianqingren/Desktop/accurac/judge.txt");
ofstream final_s("/Users/nianqingren/Desktop/accurac/final.txt");

struct student
{
    string school;
    string name_s;
    string snum;
    string phonenum;
    double scor[7];
    double ave;
}s[10];
struct judge
{
    string name_j;
    double scor[5];
}ju[7];

int main(int argc, const char * argv[]) {
    
    int n1=0,i=0;
    while(!stu.eof())
    {
        n1++;
        stu >> s[i].school >> s[i].snum >> s[i].name_s >>s[i].phonenum;
        i++;
    }
    int n2=1,j=0;
    while(!judge.eof())
    {
        n2++;
        getline(judge,ju[j].name_j,' ');
        for(int i=0; i<5; i++)
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
        //  cout << sum <<" "<<min <<" " << max <<endl;
        s[i].ave=(sum-min-max)/5;
    }
    student sm;
    for(int i=0; i<n1; i++)
    {
        for(int j=i; j<n1; j++)
        {
            if(s[i].ave<s[j].ave)
            {
                sm=s[j];
                s[j]=s[i];
                s[i]=sm;
            }
        }
    }
    
    final_s << left << setw(22) << "学院" << left << setw(22) << "学号" << left << setw(15) << "姓名" << left << setw(15) << "平均成绩" << left << setw(15) << "联系方式" << endl;
    cout << left << setw(22) << "学院" << left << setw(22) << "学号" << left << setw(15) << "姓名" << left << setw(15) << "平均成绩" << setw(15) << "联系方式" << endl;
    
    for(int i=0; i<n1; i++)
    {
        final_s << left << setw(20) << s[i].school << left << setw(20) << s[i].snum << left << setw(15) << s[i].name_s << left << setw(10) << s[i].ave << left << setw(15) << s[i].phonenum<<endl;
        
        cout << left << setw(20) << s[i].school << left << setw(20) << s[i].snum << left << setw(15) << s[i].name_s << left << setw(10) << s[i].ave << left << setw(15) << s[i].phonenum << endl;
    }
    
    final_s.close();
    return 0;
}
