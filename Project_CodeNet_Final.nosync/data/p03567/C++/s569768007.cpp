#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    string s;
    cin >> s;
    bool ok=false;
    rep(i,s.size()) if(s.substr(i,2)=="AC") ok=true;
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}