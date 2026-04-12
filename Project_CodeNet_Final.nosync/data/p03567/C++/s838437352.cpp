#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n=0;
    string s;
    cin>>s;
    for (i=0;i<s.length();i++)
    if (s[i]=='A'&&s[i+1]=='C') 
    { cout<<"Yes"<<endl; return 0; }
    cout<<"No"<<endl;
    return 0;
}