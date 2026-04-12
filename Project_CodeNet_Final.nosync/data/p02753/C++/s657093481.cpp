#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	string s;
    cin>>s;
    int count=0,count1=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='A')
            count++;
        else count1++;
    }
    if(count&&count1)
        cout<<"Yes\n";
    else cout<<"No"<<endl;
	return 0;
}