#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <utility>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
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
 
vector<int> G[100005];
std::vector<P> tree[100010];
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
 
ll i,j,k;
ll n,m;
ll a,b;
ll x[200005],y[200005];

int main(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x[i];
		y[i]=x[i];
	}
	sort(x,x+n);
	a=x[n/2-1];
	b=x[n/2];
	for(i=0;i<n;i++){
		if(y[i]<=a){
			cout<<b<<endl;
		}else{
			cout<<a<<endl;
		}
	}
	

	
	
	return 0;
}