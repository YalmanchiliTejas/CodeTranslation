#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='A'){ cnt++;}
    }
    
    if(cnt==s.length() || cnt==0)
    {
        //cout<<cnt<<endl;
		cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
	return 0;
}