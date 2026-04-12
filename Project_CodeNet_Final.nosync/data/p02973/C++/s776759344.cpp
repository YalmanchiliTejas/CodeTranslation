#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)

vector<ll> lis;
ll n,a[100010];

void init(){
	cin >> n;
	rep(i,n)cin>>a[i];
}

int main(){
	init();
	rep(i,n){
		auto it = upper_bound(lis.begin(), lis.end(), a[i], greater<>());
		if (it == lis.end()) lis.push_back(a[i]);
		else *it = a[i];
	}
	// rep(i,lis.size())cerr<<lis[i]<<endl;
	cout << lis.size() << endl;
	return 0;
}
