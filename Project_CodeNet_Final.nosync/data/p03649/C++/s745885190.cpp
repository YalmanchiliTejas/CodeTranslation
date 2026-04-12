#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 7;

int N;
ll A[51];

int main() {
	cin>>N;
	rep(i,N) cin>>A[i];
	
	ll ret=0;
	rep(x,1000000) {
		rep(i,N) if(A[i]>=N) {
			ll del=A[i]/N;
			ret += del;
			A[i] -= del*N;
			rep(j,N) if(i!=j) A[j] += del;
		}
	}
	
	cout<<ret<<endl;
    return 0;
}