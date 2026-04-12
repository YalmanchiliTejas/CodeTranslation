#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin>>s;
    set<char> x;
    for(auto l : s)
    {
        x.insert(l);
    }
    if(x.size()==1) cout<<"No";
    else cout<<"Yes";
}

