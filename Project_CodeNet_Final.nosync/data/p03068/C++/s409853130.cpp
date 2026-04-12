#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n;

    string s;

    cin>>s;

    cin >> k;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=s[k-1]) cout<<"*";

        else cout<<s[i];
    }
    return 0;
}
