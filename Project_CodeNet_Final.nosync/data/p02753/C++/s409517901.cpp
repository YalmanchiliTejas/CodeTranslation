#include<iostream>
#include<cmath>
#include<string>
#define ll long long 
using namespace std;

int main()
{
    string str;
    cin>>str;
    int k=0,p=0;
    int i;
    for(i=0;i<str.size();i++)
    {
    	if(str[i]=='A')k++;
    	else p++;
    	
    }
    if(k&&p)cout<<"Yes";
    else cout<<"No";
	return 0;
}