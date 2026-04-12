#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define repR(i, n) for(ll i = n; i >= 0; ++i)
#define FDS(i, n) for(ll i = 0; i < n; ++i)
#define FDSR(i, n) for(ll i = n; i >= 0; ++i)
#define FOR(i, m, n) for(ll i = m; i < n; ++i)
#define FORR(i, m, n) for(ll i = m;i >= n;--i)
#define VSORT(v) sort(v.begin(), v.end());
#define INF 999999999
#define itn ll
#define ednl endl
using namespace std;
typedef long long ll;template<typename Typell>Typell G_C_D(Typell a, Typell b){if (a < 0) a = -a;if (b < 0) b = -b;while (b != 0) {a %= b;if (a == 0) return b;b %= a;}return a;}template<typename Typell>
Typell G_C_D(const std::vector<Typell> &list){Typell a = list[0];for (size_t i = 1; i < list.size(); ++i) {a = G_C_D(a, list[i]);}return a;}template<typename Typell>Typell L_C_M(Typell a, Typell b) {if( a == 0 && b == 0)return 0;return a / G_C_D(a, b) * b;}
template<typename Typell>Typell L_C_M(const std::vector<Typell> &list){Typell a = list[0];for (size_t i = 1; i < list.size(); ++i) {a = L_C_M(a, list[i]);}return a;}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int H,W;
	cin>>H>>W;
	vector<string> mass(H);
	FDS(i,H){
		cin>>mass[i];
	}
	vector<int> yoko(W);
	vector<int> tate(H);
	FDS(i,H){
		FDS(j,W){
			if(mass[i].at(j)=='#'){
				yoko[j]++;
				tate[i]++;
			}
		}
	}
	FDS(i,H){
	    int sum=0;
		FDS(j,W){
			if(yoko[j]&&tate[i]){
				cout<<mass[i].at(j);
			}
			if(mass[i].at(j)=='.'){
				sum++;
			}
		}
		if(sum!=W){
			cout<<endl;
		}
	}
}