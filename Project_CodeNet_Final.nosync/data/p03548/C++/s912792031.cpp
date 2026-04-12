#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<utility>
#include<array>
#include<cassert>
#include<list>

using namespace std;

#define SPEEDY cin.tie(0);ios::sync_with_stdio(false);

#define REP(i,n) for(int i=0;i<(n);i++)
#define ARREP(i,n,X) for(int i=0;i<(n);i++)cin>>X[i]
#define FOR(i,X,n) for(int i=(X);i<(n);i++)
#define EREP(i,n) for(int i=1;i<=n;i++)

#define DEB(X) if(mode==1)cout<< #X <<": "<<X<<" ";
#define DEB2(X) if(mode==1)cout<<X<<" ";
#define ARDEB(i,X) if(mode==1)cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define FORDEB(n,X) if(mode==1)for(int i=0;i<(n);i++)ARDEB(i,X)
#define END if(mode==1)cout<<endl;

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define ALL(X) X.begin(),X.end()
struct edge{int to,cost;};
struct P2{int x,y;};
//struct edge{int from,cost,to;};

const int MOD7=1000000007;
const int INF=100000000;
int mode=0;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<(a-c)/(b+c)<<endl;
	return 0;
}