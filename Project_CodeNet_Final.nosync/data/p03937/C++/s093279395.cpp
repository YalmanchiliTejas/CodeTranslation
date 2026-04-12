#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
using namespace std;
typedef  long long int lint;
typedef pair<int, int> IP;
typedef pair<lint, lint> LLP;
typedef pair<char, char>CP;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define llower(v,hoge) *lower_bound(v.begin(), v.end(), hoge)
#define lupper(v,hoge) *upper_bound(v.begin(), v.end(), hoge)



int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>>A(H, vector<char>(W));
	rep(i, H) {
		rep(j, W) {
			cin >> A[i][j];
		}
	}
	int nx = 0;
	int ny = 0;
	while (1) {
		if (nx == H - 1 && ny == W - 1) {
			A[nx][ny] = '.';
			break;
		}
		else if (nx + 1 < H&&A[nx + 1][ny] == '#') {
				A[nx][ny] = '.';
				nx++;
			}
		else if (ny + 1 < W&&A[nx][ny + 1] == '#') {
				A[nx][ny] = '.';
				ny++;
			}
		else {
			cout << "Impossible" << endl;
			return 0;
		}
	}
	
	rep(i, H) {
		rep(j, W) {
			if (A[i][j] == '#') {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;


}
