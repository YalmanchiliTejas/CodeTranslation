#include "bits/stdc++.h"

#define REP(i, n ,N) for(ll i = (n); i < (N); i++)
#define RREP(i, n ,N) for(ll i = (N-1); i >= (n); i--)
#define p(s) cout<<(s)<<endl
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
ll inf = 1e18;

ll N, M;

int main(){
	cin >> N >> M;
	if(N==M){
		p("Yes");
	}else{
		p("No");
	}

	return 0;
}