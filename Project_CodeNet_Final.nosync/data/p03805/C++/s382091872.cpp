//おまじない
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define INF 1e9+7
#define rep(i,m,n) for(int i=m;i<n;i++)
#define mrep(i,m,n) for(int i=m;i>n;i--)
#define NO cout<<"NO"<<endl;
#define YES cout << "YES"<<endl;
#define No cout << "No"<<endl;
#define Yes cout << "Yes"<<endl;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

int n, m;
int ans = 0;
int pass[8][8] = { 0 };
bool city[8];
int reach = 1;

void cal(int s) {
	if (reach == n) {
		ans++;
		return;
	}
	else {
		rep(i, 0, n) {
			if (pass[s][i] == 1 && !city[i]) {
				city[i] = true;
				reach++;
				cal(i);
				city[i] = false;
				reach--;
			}
		}
	}
	return;
}

int main() {

	cin >> n >> m;
	rep(i, 0, m) {
		int a, b; cin >> a >> b;
		pass[a - 1][b - 1] = pass[b - 1][a - 1] = 1;
	}

	rep(i, 0, n) {
		city[i] = false;
	}
	city[0] = true;
	cal(0);

	cout << ans << endl;

	return 0;
}
