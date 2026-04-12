#include<iostream>
#include<string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
    string s;
    cin>>s;
    bool flag=false;
    rep(i,s.size()-1)
    {
        if(s[i]!=s[i+1])
        {
            flag=true;
            break;
        }
    }
    if(flag)cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}