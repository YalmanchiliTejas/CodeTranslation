#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;

//const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main()
{
	int h, w;

	cin >> h >> w;

	vector<int> y;

	string a[h];

	REP(i, h) cin >> a[i];

	REP(i, h){
		int count = 0;
		REP(j, w){
			if (a[i][j] == '.') count++;
		}
		if (count == w) y.push_back(i);
	}

	vector<int> x;

	REP(j, w){
		int count = 0;
		REP(i, h){

			if (a[i][j] == '.') count++;

		}
		if (count == h) x.push_back(j);
	}

	REP(i, h){
		bool flag = true;
		for (int nakamii : y){
			if (nakamii == i) flag = false;
		}
		if (flag == false) continue;
		REP(j, w){
			bool flag2 = true;
			for (int nakamij : x){
				if (nakamij == j) flag2 = false;
			}
			if (flag2 == false) continue;

			cout << a[i][j];

		}

		cout << endl;
	}


}
