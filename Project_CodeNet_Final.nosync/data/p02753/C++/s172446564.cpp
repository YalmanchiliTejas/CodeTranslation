#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin>>s;

    if(s.at(0) == s.at(1) && s.at(0) == s.at(2) && s.at(1) == s.at(2))
    {
        cout<<"No"<<endl;
        return 0;
    }
    else
    {
        cout<<"Yes"<<endl;
        return 0;
    }

    return 0;
}