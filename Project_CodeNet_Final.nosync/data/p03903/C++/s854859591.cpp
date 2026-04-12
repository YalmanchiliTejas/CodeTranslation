// #pragma GCC target("avx2")  // CPU 処理並列化
// #pragma GCC optimize("O3")  // CPU 処理並列化
// #pragma GCC optimize("unroll-loops")  // 条件処理の呼び出しを減らす
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
#include<numeric>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
const int C_SIZE = 3121000;
long long fact[C_SIZE];
long long finv[C_SIZE];
long long inv[C_SIZE];
long long Comb(int a,int b){
 	if(a<b||b<0)return 0;
 	return fact[a]*finv[b]%mod*finv[a-b]%mod;
}
void init_C(int n){
	fact[0]=finv[0]=inv[1]=1;
	for(int i=2;i<n;i++){
		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	}
	for(int i=1;i<n;i++){
		fact[i]=fact[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}
long long pw(long long a,long long b){
	if(a<0LL)return 0;
	if(b<0LL)return 0;
	long long ret=1;
	while(b){
		if(b%2)ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
// ここから編集しろ
int UF[4100];
vector<int>s[4100];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;
	if(UF[a]>UF[b])swap(a,b);
	UF[a]+=UF[b];UF[b]=a;
	for(int i=0;i<s[b].size();i++)s[a].push_back(s[b][i]);
	s[b].clear();
}
pair<int,pair<int,int> > edge[410000];
vector<pair<int,pair<int,int> > >v;
int neg[4100][4100];

int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++){
		int p,q,r;scanf("%d%d%d",&p,&q,&r);
		p--;q--;
		edge[i]=make_pair(r,make_pair(p,q));
	}
	std::sort(edge,edge+b);
	long long tmp=0;
	for(int i=0;i<a;i++)s[i].push_back(i);
	for(int i=0;i<a;i++)UF[i]=-1;
	for(int i=0;i<b;i++){
		if(FIND(edge[i].second.first)==FIND(edge[i].second.second))continue;
		for(int j=0;j<s[FIND(edge[i].second.first)].size();j++){
			for(int k=0;k<s[FIND(edge[i].second.second)].size();k++){
				neg[s[FIND(edge[i].second.first)][j]][s[FIND(edge[i].second.second)][k]]=
				neg[s[FIND(edge[i].second.second)][k]][s[FIND(edge[i].second.first)][j]]=
				edge[i].first;
			}
		}
		UNION(edge[i].second.first,edge[i].second.second);
		v.push_back(edge[i]);
		tmp+=edge[i].first;
	}
	int c;scanf("%d",&c);
	while(c--){
		int x,y;scanf("%d%d",&x,&y);x--;y--;
		if(x>y)swap(x,y);
		long long ret=tmp-neg[x][y];
		printf("%lld\n",ret);
	}
}