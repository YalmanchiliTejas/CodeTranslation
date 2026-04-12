//
#include <bits/stdc++.h>

// #include "../../template-proj/myMente.h"

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

#define MOD 1000000007
#define rp(i,n) for(int i=0;i<(n);i++)
#define up(i,s,e,d) for(int i=(s);i<(e);i+=(d))
#define ot(x) cout<<(x)
#define ote(x) cout<<(x)<<endl

int main(){
	int n;cin>>n;
	int ans = 0;
	vi h(n);
	int maxi = 1;
	rp(i,n){
		cin>>h[i];
		if(maxi<=h[i]){
			maxi = h[i];
			++ans;
		}
	}

	ote(ans);
}
