#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 1000000007
#define MOD 1000000007
#define EPS 1e-10
#define MAX_N 100100
#define MAX_M 100100

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;
typedef pair<ll, string> PLS;

ll n, color;

int main(){
	while (cin >> n&&n){
		V vi;
		REP(i, n){
			ll ncolor;
			if (i % 2 == 0){
				cin >> ncolor;
				if (i == 0){
					color = ncolor;
					vi.push_back(1);
				}
				else{
					if (color == ncolor)vi[vi.size() - 1]++;
					else {
						color = ncolor;
						vi.push_back(1);
					}
				}
			}
			else{
				cin >> ncolor;
				if (ncolor != color){
					color = ncolor;
					ll num = vi[vi.size() - 1] + 1;
					vi.pop_back();
					if (vi.empty())vi.push_back(num);
					else vi[vi.size() - 1] += num;
				}
				else{
					vi[vi.size() - 1]++;
				}
			}
			//REP(i, vi.size()){
			//	cout << vi[i] << " ";
			//}
			//cout << endl;
		}
		//cout << color;
		ll ans = 0, size = vi.size();
		for (int i = size - 1; i >= 0; i--){
			if (color == 0){
				if ((size - 1 - i) % 2 == 0)ans += vi[i];
			}
			else {
				if ((size - 1 - i) % 2 == 1)ans += vi[i];
			}
		}
		cout << ans << endl;
	}
}