#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll inf=1ll<<60;

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,i,j,t,m;
	cin>>n;
	vector<vector<ll>> p(n,vector<ll> (26,0));
	vector<string> g(n);
	for (i=0;i<n;i++){
		cin>>g[i];
	}
	for (i=0;i<n;i++){
		for (j=0;j<g[i].size();j++){
			t=g[i][j]-'0';
			t-=49;
			p[i][t]++;
		}
	}
	for (i=0;i<26;i++){
		m=inf;
		for (j=0;j<n;j++){
			m=min(m,p[j][i]);
		}
		for (j=0;j<m;j++){
			cout<<(char)(i+97);
		}
	}
	return 0;
}