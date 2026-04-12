#include <bits/stdc++.h>
using namespace std;
string s,y;
int x;
int main()
{
    cin>>y;
    s+=y;
    cin>>y;
    s+=y;
    cin>>y;
    s+=y;
    x=atoi(s.c_str());
    if(x%4==0)cout<<"YES";
    else cout<<"NO";
}
