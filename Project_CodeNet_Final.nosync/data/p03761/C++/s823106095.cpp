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

int main() {

	int cou[50][26] = { 0 };
	vector<string> s(50);
	int al[26] = { 0 };

	int n;
	cin >> n;
	rep(i, 0, n) {
		cin >> s[i];
	}

	rep(i, 0, 26) {
		al[i] = 2501;
	}

	rep(i, 0, n) {
		rep(j, 0, s[i].size()) {
			cou[i][(int)(s[i][j]) - 97]++;
		}
	}

	rep(i, 0, n) {
		rep(j, 0, 26) {
			al[j] = min(al[j], cou[i][j]);
		}
	}

	rep(i, 0, 26) {
		if (al[i] != 0 && al[i] != 2501) {
			while (al[i] > 0) {
				cout << (char)(i + 97);
				al[i]--;
			}
		}
	}

	cout << endl;


	return 0;
}