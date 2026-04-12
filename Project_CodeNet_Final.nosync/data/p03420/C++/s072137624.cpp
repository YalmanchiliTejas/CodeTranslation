#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <utility>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
long long int INF = 1e18;
double Pi = 3.141592653589;
const int mod = 1000000007;
// memset(a,0,sizeof(a)); →全部０にする
 
struct edge{int to,cost;};
vector<int> G[100005];
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
 
std::vector<P> tree[100010];
ll i,j;

ll n,m,ans=0;
ll a,b,c,k,nom,num;

int main(){
	cin>>n>>k;
	for(b=k+1;b<=n;b++){
		nom = ((n-k)/b)+1;
		num = (nom-1)*b+k;
		num += b-k-1;
		if(num>n && k!=0){
			ans += nom*(b-k)-num+n;
		}else if(k!=0){
			ans += nom*(b-k);
		}
		if(k==0){
			ans += n;
		}
	}
	cout<<ans<<endl;
	return 0;
}