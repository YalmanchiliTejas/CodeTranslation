#include "bits/stdc++.h"
#define MAXN 100009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
int main(){
    //~ freopen("file.in", "r", stdin);
    int n,k;
    ll ans=0;
    scanf("%d%d",&n,&k);
    if(!k){
		printf("%lld\n",n*1LL*n);
		return 0;
	}
	for(int i=k+1;i<=n;i++){//second number
		for(int j=0;j<=n;j+=i){//first number
			int a=j+k,b=min(n,j+i-1);
			ans+=max(0,b-a+1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
