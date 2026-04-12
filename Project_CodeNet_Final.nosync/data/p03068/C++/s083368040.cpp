#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<int, P> E;
#define MOD (1000000007ll)
#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a += b;
	a %= MOD;
}

int main(void){
	int n,k,i;
	string s;
	cin >> n;
	cin >> s;
	cin >> k; --k;
	for(i=0; i<n; ++i){
		if(s[i]!=s[k]){
			s[i] = '*';
		}
	}
	cout << s << endl;
	return 0;
}
