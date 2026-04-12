#include "bits/stdc++.h"
#define REP(i,n,N) for(ll i=n; i<N; i++)
#define p(s) cout<<(s)<<endl
#define p2(a,b) cout<<(a)<<" "<<(b)<<endl

using namespace std;
typedef long long ll;

int N,A,B,C,X;
int method(int x){
	return (A*x+B)%C;
}

int main() {
	while(1) {
		cin >> N >> A >> B >> C >> X;
		vector<int> rand(N);
		if (N == 0)break;
		REP(i,0,N) cin >> rand[i];

		int idx=0,ans=-1;
		REP(i,0,10001){
			if(i==0){
				if(X==rand[0])idx++;
				if(idx==N){
					ans=i;
					break;
				}
				continue;
			}
			X=method(X);
			if(rand[idx]==X){
				idx++;
			}
			if(idx==N){
				ans=i;
				break;
			}
		}
		p(ans);
	}
	return 0;
}
