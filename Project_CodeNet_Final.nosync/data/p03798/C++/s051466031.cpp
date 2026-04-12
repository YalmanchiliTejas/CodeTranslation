#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//#define mod 10007
using  namespace std;
int maxn (int a,int b,int c){return max(max(a,b),max(b,c));}
char num[200050]="\0";
char a[200050];
int n;
int judge()
{
    for(int i=1;i<n-1;i++)
        {
            if(i==n-2)
            {
                if(num[i]=='S')
                {
                    if(a[i]=='o')
                    {
                        if(num[i-1]==num[i+1])
                        {
                            if(num[i+1]=='S'&&(a[i+1]=='o'&&num[i]==num[0]||a[i+1]=='x'&&num[i]!=num[0])||num[i+1]=='W'&&(a[i+1]=='x'&&num[i]==num[0]||a[i+1]=='o'&&num[i]!=num[0]))
                           {
                               cout<<num<<endl;
                               return 1;
                           }
                           else return 0;
                        }
                        else return 0;
                    }
                    else {
                        if(num[i-1]!=num[i+1])
                        {
                             if(num[i+1]=='S'&&(a[i+1]=='o'&&num[i]==num[0]||a[i+1]=='x'&&num[i]!=num[0])||num[i+1]=='W'&&(a[i+1]=='x'&&num[i]==num[0]||a[i+1]=='o'&&num[i]!=num[0]))
                           {
                               cout<<num<<endl;
                               return 1;
                           }
                           else return 0;
                        }
                        else return 0;
                    }
                }
                else {
                    if(a[i]=='x')
                    {
                        if(num[i-1]==num[i+1])
                        {
                             if(num[i+1]=='S'&&(a[i+1]=='o'&&num[i]==num[0]||a[i+1]=='x'&&num[i]!=num[0])||num[i+1]=='W'&&(a[i+1]=='x'&&num[i]==num[0]||a[i+1]=='o'&&num[i]!=num[0]))
                           {
                               cout<<num<<endl;
                               return 1;
                           }
                           else return 0;
                        }
                       else return 0;
                    }
                    else {
                        if(num[i-1]!=num[i+1])
                        {
                             if(num[i+1]=='S'&&(a[i+1]=='o'&&num[i]==num[0]||a[i+1]=='x'&&num[i]!=num[0])||num[i+1]=='W'&&(a[i+1]=='x'&&num[i]==num[0]||a[i+1]=='o'&&num[i]!=num[0]))
                           {
                               cout<<num<<endl;
                               return 1;
                           }
                           else return 0;
                        }
                        else return 0;
                    }
                }
            }
            if(num[i]=='S')
            {
                if(a[i]=='o'){
                    num[i+1]=num[i-1];
                }
                else {
                    if(num[i-1]=='S') num[i+1]='W';
                    else num[i+1]='S';
                }
            }
            else //num[1]=='W'
            {
                if(a[i]=='x'){
                    num[i+1]=num[i-1];
                }
                else {
                    if(num[i-1]=='S') num[i+1]='W';
                    else num[i+1]='S';
                }
            }
        }
}
int main()
{
    cin>>n;
    getchar();
    for(int i=0;i<n;i++)
        scanf("%c",&a[i]);
    num[0]='S';
    if(a[0]=='o')
    {
        num[1]='S';num[n-1]='S';
        if(judge()==1) return 0;
        num[1]='W';num[n-1]='W';
        if(judge()==1) return 0;
    }
    else {
        num[1]='S';num[n-1]='W';
        if(judge()==1) return 0;
        num[1]='W';num[n-1]='S';
        if(judge()==1) return 0;
    }
    num[0]='W';
    if(a[0]=='x')
    {
        num[1]='S';num[n-1]='S';
        if(judge()==1) return 0;
        num[1]='W';num[n-1]='W';
        if(judge()==1) return 0;
    }
    else {
         num[1]='S';num[n-1]='W';
         if(judge()==1) return 0;
         num[1]='W';num[n-1]='S';
         if(judge()==1) return 0;
    }
    cout<<-1<<endl;
    return 0;
}
