
#include<bits/stdc++.h>
#define se second
#define fi first
#define pb push_back
#define cn cout<<"\n"
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repr(i,a,b) for(int i = a; i >= b; i--)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

#define _ ios::sync_with_stdio(0); cin.tie(0);

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define ll long long
#define vll vector<ll>
#define flush fflush(stdout)

const int INF = 1e8;
const ll MOD = 1e9 + 7;

using namespace std;

int main(){
	_

	int t = 1;

	cin>>t;

	vi v;
	int aux;
	int ans = 0;
	rep(i, 0, t){
		cin>>aux;

		bool y = 1;
		rep(j, 0, v.size())
			if(v[j] > aux) y = 0;

		v.pb(aux);
		if(y) ans++;
	}

	cout<<ans; cn;
	return 0;
}