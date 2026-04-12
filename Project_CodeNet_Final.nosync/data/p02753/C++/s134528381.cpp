 #include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<string.h>
using namespace std;
int main()
{
   string s;
   cin>>s;
   int count=0;
   int count1=0;
   for(int i=0;i<3;i++)
   {
       if(s[i]=='A')
       count++;
       else if(s[i]=='B')
       count1++;
   }
   if(count==3||count1==3)
   cout<<"No"<<endl;
   else
   cout<<"Yes"<<endl;
}
