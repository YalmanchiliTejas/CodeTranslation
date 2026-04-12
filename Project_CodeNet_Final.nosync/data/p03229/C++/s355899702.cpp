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
#include<deque>
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
	ll n,a[100010],ans=0,ans2=0;
	cin>>n;
	REP(i,n){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n%2==0){
		for(int i=0;i<(n-1)/2;i++){
			ans+=(a[n-i-1]-a[i])*2;
		}
		ans+=a[(n-1)/2+1]-a[(n-1)/2];
		cout<<ans<<endl;
	}
	else{
		for(int i=0;i<(n-2)/2;i++){
			ans+=(a[n-i-1]-a[i])*2;
			ans2+=(a[n-i-1]-a[i])*2;
		}
		ans+=a[(n-2)/2+2]+a[(n-2)/2+1]-a[(n-2)/2]*2;
		ans2+=a[(n-2)/2+2]*2-a[(n-2)/2+1]-a[(n-2)/2];
		cout<<std::max(ans,ans2)<<endl;
	}
	return 0;
}
/*
N=6
0 1 2 3 4 5
N=5
0 1 2 3 4
*/