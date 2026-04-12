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



int main() {

	int w, h;
	char str[101][101];
	int ch[100] = { 0 };
	int cw[100] = { 0 };

	cin >> h >> w;
	rep(i, 0, h) {
		rep(j, 0, w) {
			cin >> str[i][j];
		}
	}

	rep(i, 0, h) {
			rep(j, 0, w) {
				if(str[i][j]!='.'){
					break;

				}
				if (j == w - 1) { ch[i] = 1; }
			}
	}

	rep(i, 0, w) {
			rep(j, 0, h) {
				if (str[j][i] != '.') {
					break;

				}
				if (j == h - 1) { cw[i] = 1; }
			}
	}



	rep(i, 0, h) {
		if (ch[i] != 1) {
			rep(j, 0, w) {
				if (cw[j] != 1) cout << str[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}
