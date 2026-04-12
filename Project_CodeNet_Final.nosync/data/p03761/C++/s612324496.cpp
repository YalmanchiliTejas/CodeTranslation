#include<bits/stdc++.h>
using namespace std;
int arr[100];
map<char,int>mp[100];
map<char,int>::iterator it;

int main()
{

    int n,c=0,d=0;
    char ch;
    string s,s1;
    cin>>n;

    for (int i=0; i<n; i++ )
    {
     cin>>s;
     if(i==0){s1=s;}
     for(int j=0;j<s.length();j++)
     {
         mp[i][s[j]]++;
     }

    }
    for(it=mp[0].begin();it!=mp[0].end();++it)
    {
       ch=it->first;
       d=it->second;
       for(int i=1;i<n;i++)
       {
           c=mp[i][ch];
           if(d>c){d=c;}

       }
       for(int j=0;j<d;j++)
       {
           cout<<ch;
       }
    }
}
