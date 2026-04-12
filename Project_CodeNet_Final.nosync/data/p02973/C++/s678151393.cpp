#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

const int INF=1001001001001001001;
int dp[111111];

signed main(){
	int N;cin>>N;
	vint A(N);rep(i,N)cin>>A[i];
	rep(i,N)A[i]*=-1;
	fill_n(dp,N+1,INF);
	dp[0]=-INF;
	rep(i,N){
		int k=upper_bound(dp,dp+N+1,A[i])-dp;
		dp[k]=A[i];
	}
	cout<<lower_bound(dp,dp+N+1,INF)-dp-1<<endl;
	return 0;
}