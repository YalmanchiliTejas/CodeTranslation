#include <bits/stdc++.h>
#define ll long long int
#define F first
#define S second
const ll mod = 1e9 + 7;
const ll INF = 10000000000000;
#define pb push_back
#define deb(x) cout << '>' << #x << ':' << x << endl;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
int main()
{
    fastio;
    string s;
    cin>>s;
    bool f=false;
    for(ll i=0;i<2;++i){
        if(s[i]!=s[i+1]) f=true;
    }
    if(f) cout<<"Yes";
    else cout<<"No";
    return 0;
}
