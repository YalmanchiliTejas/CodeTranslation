#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
int N,a,d,M,K,x[200000],y[200000],z[200000];
int main(){
	cin>>N>>a>>d>>M;
	rep(i,M) cin>>x[i]>>y[i]>>z[i],y[i]--,z[i]--;
	cin>>K;
	K--;
	for(int i=M-1;i>=0;i--){
		if(x[i]==0){
			if(y[i]<=K&&K<=z[i]){
				K=y[i]+z[i]-K;
			}
		}
	}
	int v=a+d*K;
	rep(i,M){
		if(x[i]==0){
			if(y[i]<=K&&K<=z[i]){
				K=y[i]+z[i]-K;
			}
		}
		if(x[i]==1){
			if(y[i]<=K&&K<=z[i]){
				v++;
			}
		}
		if(x[i]==2){
			if(y[i]<=K&&K<=z[i]){
				v/=2;
			}
		}
	}
	cout<<v<<endl;
}