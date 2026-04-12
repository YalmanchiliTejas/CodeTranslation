#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<ll, int> P;
#define MOD (1000000007ll)
#define l_ength size

ll sq(ll x){
	return x*x;
}

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

bool isvowel(char c){
	int i;
	string v="aeiou";
	for(i = (v.size()-1); i>=0; --i){
		if(c == v[i]){
			return true;
		}
	}
	return false;
}

int main(void){
	int n,m,a,b,i,ans=0,prev;
	bool path[10][10],flag;
	vector<int> v;
	fill(path[0],path[10],false);
	cin >> n >> m;
	for(i=0; i<m; ++i){
		cin >> a >> b;
		a--;
		b--;
		path[a][b] = true;
		path[b][a] = true;
	}
	for(i=1; i<n; ++i){
		v.push_back(i);
	}
	do{
		prev = 0;
		flag = true;
		for(i=(v.size()-1); i>=0; --i){
			if(!path[prev][v[i]]){
				flag = false;
				break;
			}
			prev = v[i];
		}
		if(flag){
			ans++;
		}
	}while(next_permutation(v.begin(), v.end()));
	cout << ans << endl;
	return 0;
}