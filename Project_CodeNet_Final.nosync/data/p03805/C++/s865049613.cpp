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


//(int)'a'は97 (int)'A'は65
//おまじない

int N, M;
bool jud[8]= { 0 };
int path[8][8]= { 0 };
int ans = 0;
int c = 1;


void cal(int s = 0) {
	if (c == N) {
		ans++;
		return;
	}
	else {
		if (s == 0) {
			c = 1;
			rep(i, 0, N) { jud[i] = false; }
		}
		rep(i, 1, N) {
			if (path[s][i] == 1 && !jud[i]) {
				c++;
				jud[i] = true;
				cal(i);
				c--;
				jud[i] = false;
			}
		}


	}
	return;
}

int main() {

	cin >> N >> M;
	rep(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		path[a][b] = 1; path[b][a] = 1;
	}

	cal();

	cout << ans << endl;


	return 0;
}
