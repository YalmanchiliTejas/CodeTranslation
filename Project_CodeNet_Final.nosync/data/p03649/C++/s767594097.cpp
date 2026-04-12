#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;


// bool judge(ll K){
// 	ll b;
// 	rep(i,N){
// 		b = a[i]-(N-1-K);
// 		if(b>0){
// 			K -= b/(N+1);
// 			if(b%(N+1)>0)K-=1;
// 		}
// 	}
// 	if(K>=0){
// 		return true;
// 	}else{
// 		return false;
// 	}
// }

int main(void){
	ll N, a[52], K=0,L;
	cin>>N;
	rep(i,N){
		cin>>a[i];
		K+=a[i];
	}
	K -= N*(N-1);//最低必要な回数。
	L = K;
	if(L>0){
		rep(i,N)a[i] += K;
		rep(i,N){
			if(K > a[i]/(N+1)){
				K -= a[i]/(N+1);
				a[i] %= N+1;
			}else{
				a[i] -= K*(N+1);
				break;
			}
		}
	}else{
		L=0;
	}
	//合計値がN(N-1)を下回った後のシミュレーション。
	// cout<<L<<endl;
	bool ok;
	while(1){
		ok = true;
		rep(i,N)if(a[i]>N-1){
			a[i] -= N+1;
			L++;
			ok=false;
			break;
		}
		if(ok)break;
		rep(i,N)a[i]++;
	}
	cout<<L<<endl;
	return 0;
}