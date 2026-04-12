#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define ld long double
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<ll>
#define vii vector<pii>
#define pb push_back
#define mp  make_pair
#define all(v) (v).begin(), (v).end()

#define pb push_back
#define mp make_pair
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
ll INF = 1e6;

void solve()
{
    string s;
    cin>>s;
    if(s[0]!=s[1] || s[1]!=s[2])
    {
        cout<<"Yes";
    }
    else
        cout<<"No";
}

 
int main()
{
    SPEED;
    ll t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
