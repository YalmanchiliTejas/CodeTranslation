#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s;
   int countA=0,countB=0,i;
   cin>>s;
   for(i=0;i<s.length();i++)
   {
     if(s[i]=='A')countA++;
     else countB++;
   }
   if(countA==2||countB==2)cout<<"Yes"<<endl;
   else cout<<"No"<<endl;

}

