#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,M,W,T;
string S[10];
map<string,int> m;
int V[10];
ll P[10];
int L[10],X[10],Y[10];
int R[10][10];
ll Q[10][10];
int mindist[1<<7];
ll mincost[8];
ll gain[1<<7];
int dp[1<<7][7];
ll dp2[10][10010];
ll dp3[10010];
int dist(int a,int b){
	return abs(X[a]-X[b])+abs(Y[a]-Y[b]);
}
int main(){
	scanf("%d %d %d %d",&N,&M,&W,&T);
	for(int i=0;i<M;i++){
		cin >> S[i] >> V[i] >> P[i];
		m[S[i]]=i;
	}
	for(int i=0;i<(1<<N);i++){
		for(int j=0;j<N;j++){
			dp[i][j]=INF;
		}
	}
	for(int i=0;i<N;i++){
		cin >> L[i] >> X[i] >> Y[i];
		dp[(1<<i)][i]=abs(X[i])+abs(Y[i]);
		string tmp;
		for(int j=0;j<L[i];j++){
			cin >> tmp >> Q[i][j];
			R[i][j]=m[tmp];
		}
	}
	for(int i=0;i<(1<<N);i++){
		for(int j=0;j<N;j++){
			if(dp[i][j]==INF)continue;
			for(int k=0;k<N;k++){
				if((i>>k)&1)continue;
				chmin(dp[i|(1<<k)][k],dp[i][j]+dist(j,k));
			}
		}
	}
	for(int i=0;i<(1<<N);i++){
		mindist[i]=INF;
		for(int j=0;j<N;j++){
			if(dp[i][j]==INF)continue;
			chmin(mindist[i],dp[i][j]+dp[(1<<j)][j]);
		}
	}
	for(int i=1;i<(1<<N);i++){
		if(mindist[i]>T)continue;
		for(int j=0;j<M;j++)mincost[j]=INF;
		for(int j=0;j<N;j++){
			if((i>>j)&1){
				for(int k=0;k<L[j];k++){
					chmin(mincost[R[j][k]],Q[j][k]);
				}
			}
		}
		int prev = 0;
		for(int j=0;j<M;j++){
			if(mincost[j]==INF)continue;
			for(int k=0;k<=W;k++){
				dp2[j+1][k]=dp2[prev][k];
				if(k>=V[j]){
					chmax(dp2[j+1][k],dp2[j+1][k-V[j]]+(P[j]-mincost[j]));
				}
				chmax(gain[i],dp2[j+1][k]);
			}
			prev = j+1;
		}
	}
	dp3[0]=0;
	for(int i=0;i<=T;i++){
		dp3[i+1]=dp3[i];
		for(int j=1;j<(1<<N);j++){
			if(i>=mindist[j]){
				chmax(dp3[i+1],dp3[i+1-mindist[j]]+(ll)gain[j]);
			}
		}
	}
	printf("%lld\n",dp3[T+1]);
	return 0;
}