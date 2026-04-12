#include<iostream>
#include<string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
    string r,g,b;
    cin>>r>>g>>b;
    string ans=r+g+b;
    int x=stoi(ans);
    if(x%4==0)cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}