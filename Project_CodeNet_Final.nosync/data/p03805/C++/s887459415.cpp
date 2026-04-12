#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
typedef long long ll;
const int INF = 1000000000;
const long INF64 = 1000000000000000ll;
const int MOD = 1000000007;


int main(){
	int n,m;
	std::cin >> n>>m;
	std::vector<std::vector<int> > dist(n,std::vector<int>(n));
	rep(i,n)rep(j,n)dist[i][j]=INF;
	rep(i,n)dist[i][i]=0;
	rep(i,m){
		int a,b;
		std::cin >> a>>b;
		dist[a-1][b-1]=1;
		dist[b-1][a-1]=1;
	}
	  for (int i = 0; i < n; i++)      // 経由する頂点
    	for (int j = 0; j < n; j++)    // 開始頂点
    	 for (int k = 0; k < n; k++)  // 終端
    		 dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
	std::vector<int> v;
	for (int i = 1; i < n; i++) {
		/* code */
		v.pb(i);
	}
	int counter=0;
	do {
		int len=0;
		
		len+=dist[0][v[0]];

		rep(i,n-2){
			len+=dist[v[i]][v[i+1]];
			
		}
		
		if(len==n-1)counter++;
		

	 } while (std::next_permutation(v.begin(), v.end()));
	 std::cout << counter << std::endl;
}
