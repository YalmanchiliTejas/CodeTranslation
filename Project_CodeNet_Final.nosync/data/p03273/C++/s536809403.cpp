#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR1(i,n) for(int (i)=1;(i)<(n);(i)++)
#define eFOR(i,n) for(int (i)=0;(i)<=(n);(i)++)
#define eFOR1(i,n) for(int (i)=1;(i)<=(n);(i)++)
#define SORT(i) sort((i).begin(),(i).end())
#define INF 1000000000

int main() {

	int h, w;
	string hw[110];
	cin >> h >> w;
	vector<bool> H(h, 0), W(w, 0);
	FOR(i, h) {
		cin >> hw[i];
		FOR(j, w) {;
			if (hw[i][j] == '#') {
				H[i] = 1;
				W[j] = 1;
			}
		}
	}

	FOR(i, h) {
		FOR(j, w) {
			if (H[i] == 1 && W[j] == 1)cout << hw[i][j];
		}
		if(H[i])cout << endl;
	}

	return 0;
}