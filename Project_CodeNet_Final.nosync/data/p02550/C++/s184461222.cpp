#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<iomanip>
#include<list>
#include<deque>
using namespace std;
//#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define DEB2(X) cout<<X<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define DEB2(X) {}
#define END {}
#endif
typedef long long ll;
#define int ll
#define uset unordered_set
#define umap unordered_map
//typedef std::pair<int,int> P;
struct edge{int to,cost;};
const int INF=100000000000000000;
const int INF2=9223372036854775807;
const int MOD=1000000007;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define NP(X,Y) next_permutation(X,Y)
#define setdouble(X,Y) cout<<fixed<<setprecision(X)<<Y
int ceil2(int a,int b){if(a%b==0){return a/b;}else{return a/b+1;}}
int pow2(int a,int b){int r=1;for(int i=1;i<=b;i++){r*=a;}return r;}
int Log2(int a){int t=0;while(1){if(a==0||a==1){break;}a/=2;t++;}return t;}

int N,X,M;

int pos[100010];
int num[100010];

signed main(){
	cin>>N>>X>>M;
	set<int> U;
	vector<int> v;
	int a=X;
	int t;
	bool flag=true;
	int sum=0;
	for(int i=0;i<N;i++){
		if(U.find(a)!=U.end()){
			t=i;
			flag=false;
			break;
		}
		pos[a]=i;
		U.insert(a);
		v.push_back(a);
		num[i+1]=num[i]+a;
		a=(a*a)%M;
	}
	if(flag){
		cout<<num[N]-num[0]<<endl;
		return 0;
	}
	int ans=num[pos[a]];
	ans+=(num[t]-num[pos[a]])*((N-pos[a])/(t-pos[a]));
	int l=(N-pos[a])%(t-pos[a])+pos[a];
	ans+=num[l]-num[pos[a]];
	cout<<ans<<endl;
	return 0;
}
