//By Ralif Rakhmatullin
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<math.h>
#include<cassert>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<bitset>
#include<valarray>
#include<iterator>
#include<list>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define S second
#define ld long double
#define F first
#define y1 LOL
#define ld long double
#define pb push_back
#define len length
#define sz size
#define beg begin
const ll INF = (ll)1e18 + 123;
const int inf=(int)2e9 + 123; 
const int mod=1e9+7;
using namespace std;
int n, A, B, d[21][21], f[111][111];
int main(){
	unsigned int FOR;
 	asm("rdtsc" : "=A"(FOR));
  	srand(FOR);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> A >> B;
	for(int i = 1; i <= A; i ++){
		for(int j = 1; j <= B; j ++){
			cin >> d[i][j];
		}
	}
	int n = 1;
	for(int i = 0; i <= 100; i ++){
		for(int j = 0; j <= 100; j ++){
			for(int a = 1; a <= A; a ++){
				for(int b = 1; b <= B; b ++){
					f[i][j] = max(f[i][j], d[a][b] - a * i - b * j);
				}
			}
		}
	}
	for(int a = 1; a <= A; a ++){
		for(int b = 1; b <= B; b ++){
			int res = inf;
			for(int i = 0; i <= 100; i ++){
				for(int j = 0; j <= 100; j ++){
					res = min(res, f[i][j] + a * i + b * j);
				}
			}
			if(res != d[a][b]){
				cout << "Impossible";
				return 0;
			}
		}
	}
	cout << "Possible\n";
	int s = 1, t = 202;
	cout << t << " " << 101 * 101 + 200 << endl;
	for(int i = 2; i <= 101; i ++){
		cout << i - 1 << " " << i << " X\n";
	}
	for(int i = 103; i <= t; i ++){
		cout << i - 1 << " " << i << " Y\n";
	}
	for(int i = 0; i <= 100; i ++){
		for(int j = 0; j <= 100; j ++){
			cout << i + 1 << " " << t - j << " " << f[i][j] << endl;
		}
	}
	cout << s << " " << t;
	return 0;
}                     