#include<bits/stdc++.h>
using namespace std;
int main  ()
{
    int i=0;
    char S[4];

    for(i=0;i<3;i++)
     {
         cin>>S[i];
     }

         if(S[0]==S[1] && S[0]!=S[2] || S[0]==S[2] && S[0]!=S[1] || S[1]==S[2] && S[0]!=S[1])
         {cout<<"Yes"<<endl;}
         else
         {cout<<"No"<<endl;}




}
