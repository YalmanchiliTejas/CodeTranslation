#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
typedef long long ll;
const int INF = 1000000000;
const long INF64 = 1000000000000000ll;
const ll MOD = 1000000007ll;


int main(){
	int n;
	std::cin >> n;
	char ox[n];
	std::vector<string> s(4);
	rep(i,n)std::cin >> ox[i];
	s[0]="SS";s[1]="SW";s[2]="WS";s[3]="WW";
	rep(i,4){
		string ans;
	//	std::cout << ans.size() << std::endl;
		ans.pb(s[i].at(0));
		ans.pb(s[i].at(1));
	//	std::cout << ans << std::endl;
		for (int j = 2; j <= n; j++) {
			/* code */
			if(ox[j-1]=='o'){
				if(ans[j-1]=='S')ans.pb(ans[j-2]);
				else{
					if(ans[j-2]=='W')ans.pb('S');
					else ans.pb('W');
				} 
			}else{
				if(ans[j-1]=='W')ans.pb(ans[j-2]);
				else{
					if(ans[j-2]=='W')ans.pb('S');
					else ans.pb('W');
				}
			}
			
			
		}
		if(ox[0]=='o'){
			
				if(ans[n]=='S')ans.pb(ans[n-1]);
				else{
					if(ans[n-1]=='W')ans.pb('S');
					else ans.pb('W');
				} 
			}else{
				if(ans[n]=='W')ans.pb(ans[n-1]);
				else{
					if(ans[n-1]=='W')ans.pb('S');
					else ans.pb('W');
				}
			
		}
		if(ans[n]==ans[0]&&ans[n+1]==ans[1]){
				rep(k,n)std::cout << ans[k] ;
				std::cout  << std::endl;
				exit(0);
		}
	}
	std::cout << -1 << std::endl;
}
