#include<bits/stdc++.h>
using namespace std;
string s;
char ch[100005];
bool simulate()
{
    int n=s.length();
    for(int i=1;i<=n;i++)
    {
        if(ch[i]=='S')
        {
            if(s[i]=='o')ch[i+1]=ch[i-1];
            else
            {
                if(ch[i-1]=='S')ch[i+1]='W';
                else ch[i+1]='S';
            }
        }
        else
        {
            if(s[i]=='x')ch[i+1]=ch[i-1];
            else
            {
                if(ch[i-1]=='S')ch[i+1]='W';
                else ch[i+1]='S';
            }
        }
    }
    if(ch[n]!=ch[0])return false;
    if(ch[0]=='S')
    {
        if(s[0]=='o')
        {
            if(ch[n-1]!=ch[1])return 0;
        }
        else
            if(ch[n-1]==ch[1])return 0;
    }
    else
    {
        if(s[0]=='x')
        {
            if(ch[n-1]!=ch[1])return 0;
        }
        else
            if(ch[n-1]==ch[1])return 0;
    }

    return true;
}
void print(int n)
{
    for(int i=0;i<n;i++)cout<<ch[i];
    cout<<endl;
}
int main()
{
    int n;cin>>n;
    cin>>s;
    ch[0]='S';
    ch[1]='S';
    bool f=simulate();
    if(f){
        print(n);
        return 0;
    }
    ch[0]='S',ch[1]='W';
    f=simulate();
    if(f){
        print(n);
        return 0;
    }
    ch[0]='W',ch[1]='W';
    f=simulate();
    if(f){
        print(n);
        return 0;
    }
    ch[0]='W';
    ch[1]='S';
    f=simulate();
    if(f)
    {
        print(n);
        return 0;
    }
    cout<<-1<<endl;
}
