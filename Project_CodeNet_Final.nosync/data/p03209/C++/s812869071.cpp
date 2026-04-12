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
#include<unordered_set>
#include<bitset>
using namespace std;
//#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
typedef long long int ll;
#define int long long
typedef pair<int,int> P;
struct edge{int to,cost;};
#define REP(i,n) for(int i=0;i<(n);i++)
const int INF=100000000000000000;

int A[200010],B[200010],num[200010];
int N,M,W,C,D,E,G,K,X;
int ans,ans2,sum,sum2,cnt,cnt2,Max=0,Min=INF;
string S[110],T;
vector<int> V={1},V2={1};
set<int> U;
map<int,int> H;
bool F,Q[200010];

int f(int n,int x){
	if(n==0){
		if(x<=0){
			return 0;
		}
		else{
			return 1;
		}
	}
	else if(x<=1+V[n-1]){
		return f(n-1,x-1);
	}
	else{
		return V2[n-1]+1+f(n-1,x-2-V[n-1]);
	}
}

signed main(){
	cin>>N>>X;
	REP(i,N){
		V.push_back(V[i]*2+3);
		V2.push_back(V2[i]*2+1);
	}
	cout<<f(N,X)<<endl;
	return 0;
}
//1 1
//5 3
//13 7
