#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define FORR(I,A,B) for(ll I = (B-1); I >= (A); --I)
const ll INF=1e18+7;
const ll MOD=1e9+7;

vector< vector<char> > ans(vector< vector<char> > a){
	vector< vector<char> > w;
	FOR(i,0,a.size()){
		bool add = false;
		char x = a[i][0];
		if(x=='#')add = true;
		FOR(j,0,a[i].size()){
			if(x!=a[i][j])add = true;
		}
		if(add)w.push_back(a[i]);
	}
	return w;
}

vector< vector<char> > rot90(vector< vector<char> > a){
	vector< vector<char> > w;
	ll h = a.size();
	ll ww = a[0].size();
	w.resize(ww);
	FOR(i,0,ww)w[i].resize(h);
	FOR(i,0,h){
		FOR(j,0,ww){
			w[j][i] = a[i][j];
		}
	}
	return w;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector< vector<char> > a;
	ll h,w;
	cin>>h>>w;
	FOR(i,0,h){
		vector<char> wv;
		a.push_back(wv);
		FOR(j,0,w){
			char x;
			cin>>x;
			a[i].push_back(x);
		}
	}
	a = ans(a);
	a = rot90(a);
	a = ans(a);
	a = rot90(a);
	FOR(i,0,a.size()){
		FOR(j,0,a[i].size()){
			cout<<a[i][j];
		}
		cout<<endl;
	}
}