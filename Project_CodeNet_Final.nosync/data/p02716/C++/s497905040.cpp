#include <bits/stdc++.h>

using namespace std;
#define ll long long int
vector<ll> v;
map<pair<int,int>, ll> mp;
int n;
ll solve(int st, int en, int cnt){
    if(cnt==0){
        return 0;
    }
    if((en-st+1)<(2*cnt-1) || en<st){
        return -(1ll<<60);
    }
    if(mp.count({st,cnt})) return mp[{st,cnt}];
    mp[{st,cnt}] = max(solve(st+1,en,cnt), v[st]+solve(st+2,en,cnt-1));
    return mp[{st,cnt}];
}
int main()
{
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) {cin >> v[i];}
    ll f = solve(0,n-1,n/2);
    cout << f << endl;
}
