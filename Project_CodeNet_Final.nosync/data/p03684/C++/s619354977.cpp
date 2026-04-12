#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	#include<De>
#endif
using namespace std;
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	try{
		//while(1)
		//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 1e5 +100;
P A[N];
P B[N];
int p[N];
typedef pair<int, pair<int,int>> pp ;
priority_queue<pp,vector<pp>, greater<pp> > pq;
int find(int a){
	if(p[a]<0)return a;
	return p[a] = find(p[a]);
}
void uni(int a,int b){
	if(p[a]>p[b]) swap(a,b);
	p[a]+=p[b];
	p[b] = a;
}
void inp(){
	int n;
	scanf("%d",&n);
	memset(p, -1 , sizeof(p));
	for(int i = 0;i<n;i++){
		scanf("%d%d", &A[i].first,&B[i].first);
		A[i].second = B[i].second = i+1;
	}
	sort(A,A+n);
	sort(B,B+n);
	for(int i = 1;i<n;i++){
		pq.push(pp(abs(A[i].first - A[i-1].first),P(A[i].second,A[i-1].second)));
		pq.push(pp(abs(B[i].first - B[i-1].first),P(B[i].second,B[i-1].second)));
	}
	ll cost = 0;
	while(!pq.empty()){
		pp p = pq.top();pq.pop();
		int fa = find(p.second.first);
		int fb = find(p.second.second);
		if(fa==fb)continue;
		cost += p.first;
		uni(fa,fb);
	}
	printf("%lld\n", cost);
}
//D.cc by xsthunder at Wed Jul 19 09:27:12 2017
