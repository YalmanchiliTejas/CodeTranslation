#include "bits/stdc++.h"
#define rep(i,b) for(ll i=0;i<b;i++)
#define ll long long
using namespace std;
template<typename T> void SSS(T& t) { cin >> t; }
#define SS(T, ...)      T __VA_ARGS__; SSS(__VA_ARGS__);
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define debug(x) cerr<<#x<<" "<<x<<'\n';
bool cmp(pair<ll,ll> a, pair<ll,ll> b) { return a.second < b.second; }

const int MOD = 1000000007;

int main() {
   ll a,b;cin>>a>>b;
   if(a==b)cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
}
