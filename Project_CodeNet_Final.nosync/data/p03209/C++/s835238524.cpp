#include "bits/stdc++.h"

using namespace std;
using ll=long long;
using ull=unsigned long long;

typedef pair<int,int>Pi;
typedef pair<long long,long long>P;
typedef pair<long long,P>PP;
typedef pair<P,P>PPP;

const long long MOD=1e9+7;
const long long INF=5e18;
const int di[4]={1,0,-1,0};
const int dj[4]={0,1,0,-1};

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()


P cnt[55];
ll sum[55];

ll dfs(int now,ll x){
	if(now==-1)return 0;
	ll ret=0;
	if(x==sum[now]){
		return cnt[now].sc;
	}
	if(x>(sum[now]+1)/2){
		ret+=cnt[now-1].sc+1;
		ret+=dfs(now-1,x-(sum[now]+1)/2);
	}
	else if(x==(sum[now]+1)/2){
		ret+=cnt[now-1].sc+1;
	}
	else{
		ret+=dfs(now-1,x-1);
	}
	return ret;
}

int n;
ll x;

void input(){
	cin>>n>>x;
	return;
}

void solve(){
	cnt[0]=P(0,1);
	sum[0]=1;
	for(int i=1;i<=50;i++){
		cnt[i].fr=cnt[i-1].fr*2+2;
		cnt[i].sc=cnt[i-1].sc*2+1;
		sum[i]=sum[i-1]*2+3;
	}
	cout<<dfs(n,x)<<endl;
	return;
}

int main(){
	input();
	solve();
	return 0;
}
