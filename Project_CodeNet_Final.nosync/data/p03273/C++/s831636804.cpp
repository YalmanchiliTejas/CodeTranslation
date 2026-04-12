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
	b += MOD;
	a += b;
	a %= MOD;
}

int main(void){
	int h,w,i,j;
	string a[123];
	bool r[123],c[123];
	fill(r,r+123,false);
	fill(c,c+123,false);
	cin >> h >> w;
	for(i=0; i<h; ++i){
		cin >> a[i];
		for(j=0; j<w; ++j){
			if(a[i][j] == '#'){
				r[i] = true; c[j] = true;
			}
		}
	}
	for(i=0; i<h; ++i){
		if(!r[i]){
			continue;
		}
		for(j=0; j<w; ++j){
			if(c[j]){
				cout << a[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}
