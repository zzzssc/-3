//
//  main.cpp
//  文件传输3
//
//  Created by s20181106119 on 2019/6/26.
//  Copyright © 2019 s20181106119. All rights reserved.
//



#include<iostream>
#include<fstream>
using namespace std;
struct student{
    char name1[50];       //学生姓名
    char number[50];      //学号
    char  colleage[50];   //学院
    char  speciality[50];   //专业
    char name2[8];    //裁判姓名
    int score[7];    //分数
    double ave;
};
int main()
{
    int n=5;
    student x[n];
    ifstream in("/Users/s20181106119/Desktop/学生信息.txt");
    {
        //cout << "Success !" <<endl;
        int i,l;
        for(i=0;i<5;i++)
        {
            in>>x[i].name1;//>>x[i].colleage>>x[i].number>>x[i].speciality;
            for(l=0;l<8;l++)
            {
                in>>x[i].score[l];
            }
            
        }
        in.close();
        
    }
    /*ifstream inf ("Users/s20181106119/Desktop/裁判信息及分数.txt");
     {
     //cout << "Success !" <<endl;
     int i,l;
     for(i=0;i<5;i++)
     {
     in>>x[i].name1>>x[i].colleage>>x[i].number>>x[i].speciality;
     for(l=0;l<8;l++)
     {
     in>>x[i].score[l];
     }
     
     }
     in.close();
     inf.close();
     }*/
    ofstream output("/Users/s20181106119/Desktop/最终排名.txt");
    {
        
        int i,l,sum=0,a=0;
        
        for(i=0;i<50;i++)
        {
            for(l=0;l<8;l++)
            {
                sum=sum+x[i].score[l];
            }
            x[i].ave=1.0*sum/l;
        }
        for(i=0;i<50;i++)
        {
            
            
            if(a<x[i].ave)
            {
                a=x[i].ave;
                x[i].ave=x[i+1].ave;
                x[i+1].ave=a;
            }
        }
        /*for(i=0;i<50;i++)
         {
         for(l=0;l<8;l++)
         {
         output<<x[i].name1<<x[i].ave<<i<<endl;
         }
         }*/
        for(i=0;i<5;i++)
        {
            output<<x[i].name1<<endl;
        }
        output.close();
    }
    return 0;
}
