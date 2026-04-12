
// Problem : A - Air Conditioner
// Contest : AtCoder - AtCoder Beginner Contest 174
// URL : https://atcoder.jp/contests/abc174/tasks/abc174_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define endl '\n'
#define vi vector<ll>
#define vb vector<bool>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define fi first
#define se second
#define m_p make_pair
#define vpii vector<pii>
#define vvi vector<vi>
#define vs vector<string>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const ll inf=0x3f3f3f3f3f3f3f3f;
void print(vi v){
	ll n = v.size();
	for(ll i = 0; i < n; i++)
	    cout<<v[i]<<" ";
	cout<<endl;
}
ll power(ll a, ll b){
	ll res = 1;
	while(b != 0) {
		if(b & 1)
		  res *= a;
		a = a * a;
		b /= 2;
	}
	return res;
}
int main() {
    SPEED;
    ll x;
    cin>>x;
    if(x >= 30LL) {
    	cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}