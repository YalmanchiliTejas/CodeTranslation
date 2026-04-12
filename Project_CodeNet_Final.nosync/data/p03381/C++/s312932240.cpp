#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
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
ll MOD = 1e9+7;
//LLONG_MIN




int main(void){
	ll N,A[200010],X[200010];
	scanf("%lld",&N);
	rep(i,N){
		scanf("%lld",&A[i]);
		X[i]=A[i];
	}
	sort(A,A+N);//小→大
	rep(i,N){
		ll ans;
		if(A[N/2-1]>=X[i]){
			ans=A[N/2];
		}else{
			ans=A[N/2-1];
		}
		printf("%lld\n",ans);
	}
	return 0;
}