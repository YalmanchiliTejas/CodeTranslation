#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N;cin>>N;
	long A[N];
	rep(i,0,N) cin>>A[i];
	sort(A,A+N);
	if(N % 2 == 0){
		long res = 0;
		rep(i,0,N/2) res -= A[i];
		rep(i,N/2,N) res += A[i];
		cout<<2 * res - A[N/2] + A[N/2-1]<<endl;
	}else{
		long res = 0;
		rep(i,0,N/2-1) res -= A[i];
		rep(i,N/2+1,N) res += A[i];
		long ans = 2 * res - A[N/2] - A[N/2-1];
		res = 0;
		rep(i,0,N/2) res -= A[i];
		rep(i,N/2+2,N) res += A[i];
		ans = max(ans, 2 * res + A[N/2] + A[N/2+1]);
		cout<<ans<<endl;
	}
}