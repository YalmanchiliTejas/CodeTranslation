#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A')a++;
        if(s[i]=='B')b++;
    }
    if(a==0||b==0)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
