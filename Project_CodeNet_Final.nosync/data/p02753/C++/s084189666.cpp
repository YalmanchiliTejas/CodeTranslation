#include<iostream>
using namespace std;
int main()
{
    int flag1=0,flag2=0;
    string s;
    cin>>s;
    if(s[0]=='A'||s[1]=='A'||s[2]=='A')
    {
        flag1 = 1;
    }
    if(s[0]=='B'||s[1]=='B'||s[2]=='B')
    {
        flag2 = 1;
    }
    if(flag1&&flag2)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}
