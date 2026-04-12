#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;

const int INF=1<<29;
const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
//int dp[100010]={0};//dp[i]:=i番目までで0がいくつ連続してあるか
int main(){
	int n;

	while(1){
        scanf("%d",&n);
		//int a[100010]={0};
		if(n==0)break;
		vector<pii> x(0);
		for(int i =1;i <=n;i++){
			int a;
			scanf("%d",&a);
			if(i%2){
				if(x.empty()||a!=x[x.size()-1].first){
					x.push_back(mp(a,1));
				}else{
					x[x.size()-1].second++;
				}
			}else{
				if(x[x.size()-1].first==a){
					x[x.size()-1].second++;
				}else{
					int v =x[x.size()-1].second;
					x.pop_back();
					if(!x.empty()){
						x[x.size()-1].second+=(v+1);
					}else{
						x.push_back(mp(a,v+1));
					}
				}
			}
		}
		int ans = 0;
		for(int i =0;i <x.size();i++){
			if(x[i].first==0){
				ans +=x[i].second;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}