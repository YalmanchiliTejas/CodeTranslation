#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A')a++;
        else b++;
    }
    if(a&&b)
        cout<<"Yes";
    else
        cout<<"No";
}
