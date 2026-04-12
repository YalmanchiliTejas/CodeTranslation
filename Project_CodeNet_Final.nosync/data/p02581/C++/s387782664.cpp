#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N=2005;
const int INF=123456789;
int n,tmx=-INF,ans;
int a[N*3];
vector<pair<pii,int> > vtr;
int dp[N][N],mx[N];

inline void chmax(int &x,int y){x=max(x,y);}

inline void update(int x,int y,int t){
//	printf("upd %d %d %d\n",x,y,t);
	chmax(dp[x][y],t);
	chmax(dp[y][x],t);
	chmax(mx[x],t);
	chmax(mx[y],t);
	chmax(tmx,t);
}

void tr1(int x){
	for(int i=1;i<=n;i++) vtr.push_back(make_pair(make_pair(i,x),mx[i]));
}

void tr2(int x,int y){
	vtr.push_back(make_pair(make_pair(x,y),tmx));
}

void tr3(int x,int y,int z){
	vtr.push_back(make_pair(make_pair(y,z),dp[x][x]+1));
}

int main(){
	scanf("%d",&n);
	tmx=-INF;
	for(int i=1;i<=n;i++) mx[i]=-INF;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=-INF;
	for(int i=1;i<=n*3;i++) scanf("%d",a+i);
	update(a[1],a[2],0);
	for(int i=1;i<n;i++){
		vtr.clear();
		sort(a+i*3,a+i*3+3);
		int A=a[i*3],B=a[i*3+1],C=a[i*3+2];
		if(A==B&&B==C){
			ans++;
			continue;
		}
		if(A==B||B==C){
			if(B==C) swap(A,C);
			for(int j=1;j<=n;j++) vtr.push_back(make_pair(make_pair(C,j),dp[A][j]+1));
		}
		tr1(A);tr1(B);tr1(C);
		tr2(A,B);tr2(A,C);tr2(B,C);
		tr3(A,B,C);tr3(B,A,C);tr3(C,A,B);
		for(int i=0;i<vtr.size();i++) update(vtr[i].first.first,vtr[i].first.second,vtr[i].second);
	}
//	printf("%d\n",ans);
	printf("%d\n",max(tmx,dp[a[n*3]][a[n*3]]+1)+ans);
	return 0;
}