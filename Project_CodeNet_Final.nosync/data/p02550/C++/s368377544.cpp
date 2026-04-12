#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	LL N, X, M;
	cin >> N >> X >> M;
	vector<LL> A(M+2), sum(M+2);
	vector<LL> app(M+1);
	A[1]=X, sum[1]=X, app[X]=1;
	LL ans=0;
	LL dif=0;
	for(LL i=1; i<=M; i++){
		A[i+1]=A[i]*A[i]%M;
		sum[i+1]+=sum[i]+A[i+1];
		LL k=app[A[i+1]];
		if(k){
			ans+=sum[k-1];
			dif=i-k+1;
			LL num=(N-(k-1))/dif;
			LL res=(N-(k-1))%dif;
			ans+=num*(sum[i]-sum[k-1]);
			ans+=sum[k-1+res]-sum[k-1];
			break;
		}
		else app[A[i+1]]=i+1;
	}
	cout << ans << endl;

	return 0;
}