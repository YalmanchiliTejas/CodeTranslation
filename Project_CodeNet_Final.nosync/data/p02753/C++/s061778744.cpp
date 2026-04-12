#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int a=count(s.begin(),s.end(),'A');
    int b=count(s.begin(),s.end(),'B');
    if(a&&b)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
