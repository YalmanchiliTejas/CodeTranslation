#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
using namespace std;
int main()
{
    long long n,k=0,i,t=0,j,m,b,x=0,y=0;
    cin>>n;
    string s[n];
    int a[n][26],c[26];
    for(i=0;i<n;i++)
      for(j=0;j<26;j++)
         a[i][j]=0;
    for(i=0;i<n;i++)
       cin>>s[i];
    for(i=0;i<n;i++)
       for(j=0;j<s[i].size();j++)
          {
              a[i][s[i][j]-97]++;
          }
    for(i=0;i<26;i++)
       {
           c[i]=a[0][i];
       }
    for(i=1;i<n;i++)
       for(j=0;j<26;j++)
          {
              if(c[j]>a[i][j])
                {
                    c[j]=a[i][j];
                }    
          }
    for(i=0;i<26;i++)
       {
           if(c[i]>0)
             {
                 for(j=0;j<c[i];j++)
                    cout<<char(i+97);
                 k++;    
             }
       }
    if(k==0)
      cout<<" ";
    return 0;
}