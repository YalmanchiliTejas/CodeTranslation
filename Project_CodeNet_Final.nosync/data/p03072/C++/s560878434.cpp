//Decision's template
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
using namespace std;

#define DP_maxn 16
#define maxn 1000000+10
#define INF 1000000007
#define mod 1000000007
#define mst(s,k) memset(s,k,sizeof(s))
#define eps 1e-12

typedef long long ll;

struct Edge{
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
};

/*-------------------------------template End--------------------------------*/

int n,a[30];
int ans = 1;

int main(){
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i];
	for(int i = 2;i<=n;i++){
		for(int j = 1;j<=i;j++){
			if(j == i){
				ans++;
			}
			if(a[i] >= a[j]) continue;
			else break;
		}
	}
	cout<<ans<<endl;
	return 0;
}