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
typedef pair<int,int> P;
struct edge{int to,cost;};
#define REP(i,n) for(int i=0;i<(n);i++)
const int INF=100000000;

int main(){
	int a,b,c,x,y,ans=0;
	cin>>a>>b>>c>>x>>y;
	if(a+b>=c*2){
		int dim=min(x,y);
		x-=dim,y-=dim;
		ans+=c*2*dim;
		if(a*x+b*y>c*2*max(x,y)){
			ans+=c*2*max(x,y);
		}
		else{
			ans+=a*x+b*y;
		}
	}
	else{
		ans+=a*x+b*y;
	}
	cout<<ans<<endl;
	return 0;
}