#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define INF 1000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

string ans = "Yes";

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	map<char,int> ansstr;
	map<char,int> chcnt;
	string s;
	cin >> s;
	rep(i,s.size()){
		ansstr[s[i]]++;
	}

	rep(i,N-1){
		chcnt.clear();
		cin >> s;
		rep(j,s.size()){
			chcnt[s[j]]++;
		}
		for(auto& p:ansstr){
			if(chcnt.count(p.first)){
				p.second = min(p.second,chcnt[p.first]);
			}
			else{
				ansstr.erase(p.first);
			}
		}
	}

	for(auto p:ansstr){
		rep(i,p.second){
			cout << p.first;
		}
	}
	cout << endl;

	return 0;
}