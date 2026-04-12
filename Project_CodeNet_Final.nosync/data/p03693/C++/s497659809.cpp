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
#include<experimental/any>
#include<cstring>
#include<cctype>
#include<ctime>
#include<cstdbool>
#include<cstdint>
#include<cstddef>
#include<set>
#include<unordered_set>
#include<bitset>
 
using namespace std;
using experimental::any;
 
#define SPEEDY cin.tie(0);ios::sync_with_stdio(false);
 
#define REP(i,n) for(int i=0;i<(n);i++)
#define ARREP(i,n,X) for(int i=0;i<(n);i++)cin>>X[i]
#define FOR(i,X,n) for(int i=(X);i<(n);i++)
#define EREP(i,n) for(int i=1;i<=n;i++)
#define BitFOR(N) REP(Bit,1<<(N))
 
//#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define DEB2(X) cout<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define TFDEB(f) (f)? cout<<"true ":cout<<"false ";
#define FORDEB(n,X) for(int i=0;i<(n);i++)ARDEB(i,X)
#define END cout<<endl;
#else
#define DEB(X) {}
#define DEB2(X) {}
#define ARDEB(i,X) {}
#define TFDEB(f) {}
#define FORDEB(n,X) {}
#define END {}
#endif
 
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define ALL(X) X.begin(),X.end()
struct edge{int to,cost;};
//struct edge{int from,cost,to;};
struct P2{int x,y;};
#define BIT(Bit,n) bitset<n>(Bit)
#define Endl endl
#define YN(f) cout<<((f)?"Yes":"No")<<endl
 
const int MOD7=1000000007;
const int INF=100000000;
const int SET=1000; 
 
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if((a*100+b*10+c)%4==0){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
