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
#include<unordered_map>
#include<bitset>
using namespace std;
#define INF 1000000007
#define LINF 100000000000000007
#define MOD 1000000007
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
//typedef long long int ll;
typedef pair<int,int> P;
struct edge{int to,cost;};

int ans;
int n,m;
int a[111],p[111];

int fact(int k,int x){//レベKをしたからx層
	if(k==0)return 1;
	if(x==1)return 0;
	if(1<x && x<=a[k-1]+1)return fact(k-1,x-1);
	if(x==a[k-1]+2)return p[k-1]+1;
	if(a[k-1]+2<x && x<=a[k-1]*2+2)return p[k-1]+1+fact(k-1,x-(a[k-1]+2));
	if(x==a[k-1]*2+3)return p[k-1]*2+1;
}

signed main(){
	
	cin>>n>>m;
	a[0]=1;p[0]=1;
	rep(i,n){
		a[i+1]=a[i]*2+3;
		p[i+1]=p[i]*2+1;
	}
	cout<<fact(n,m)<<endl;
	

}