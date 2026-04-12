#include<bits/stdc++.h>          
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define int long long
#define mk_p(a,b)	make_pair((a),(b))
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr long long MOD = 1000000007;

int gcd(int a,int b){return b ? gcd(b,a%b) : a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}

string mas[105];
vector<int> x;
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h,w;
	cin >> h >> w;
	rep(i,h){
		cin >> mas[i];
	}
	rep(i,h){
		bool flg = true;
		rep(j,w){
			if(mas[i][j] == '#'){
				flg = false;
				break;
			}
		}
		if(flg){
			x.emplace_back(i);
		}
	}
	vector<int> y;
	rep(i,w){
		bool flg = true;
		rep(j,h){
			if(mas[j][i] == '#'){
				flg = false;
				break;
			}
		}
		if(flg){
			y.emplace_back(i);
		}
	}
	rep(i,h){
		if(binary_search(all(x),i)) continue;
		rep(j,w){
			if(binary_search(all(y),j)) continue;
			else cout << mas[i][j];
		}
		cout << '\n';
	}
	return 0;
}
