#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> l_l;
typedef vector<ll> vel;
typedef vector<int> vei;
typedef vector<string> ves;
typedef vector<vector<int>> ve_vei;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rep2(i,n) for(int i=2;i<(int)(n);i++)
#define fs first
#define sc second
#define all(a) a.begin(),a.end()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
 
int main() {
	//cout.precision(10);
	cin.tie(0);
	ios::sync_with_stdio(false);

    int X,Y,Z; cin >> X >> Y >> Z;
    int i = 0;
    while(i * Y + (i + 1) * Z <= X) i++;
    cout << i - 1 << endl;
}