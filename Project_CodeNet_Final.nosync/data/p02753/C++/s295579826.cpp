#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int x = s.length();
    int a=0,b=0;
    for(int i=0;i<x;i++){
        if(s[i]=='A')
        a++;
        if(s[i]=='B')
        b++;
    }
    if(a==0||b==0)
    cout<<"No";
    else
    cout<<"Yes";

    return 0;
}
