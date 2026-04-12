
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <numeric>
using namespace std;
#define lint long long
#define ll long long
#define pq priority_queue
long long INF = 1e10;
#define pii pair<long long,long long>
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
/****************temporary declaration & definitoins*******************/
char g[100][100];
/**************************define functions****************************/

/****************************main function*****************************/
int main(void) {
	int h, w; cin >> h >> w;
	for (ll i = 0; i < h; i++) {
		for (ll j = 0; j < w; j++) {
			cin >> g[i][j];
		}
	}
	vector<int> hs, ws;
	for (int i = 0; i < h; i++) {
		bool check = true;
		for (ll j = 0; j < w; j++) {
			if (g[i][j] != '.') {
				check = false;
				break;
			}
		}
		if (check) hs.push_back(i);
	}
	for (int i = 0; i < w; i++) {
		bool check = true;
		for (ll j = 0; j < h; j++) {
			if (g[j][i] != '.') {
				check = false;
				break;
			}
		}
		if (check) ws.push_back(i);
	}
	for (ll i = 0; i < h; i++) {
		bool check = false;
		for (ll j = 0; j < w; j++) {
			if (!binary_search(all(hs), i) && !binary_search(all(ws), j)) {
				cout << g[i][j];
				check = true;
			}
		}
		if (check) {
			cout << endl;
		}
	}
	return 0;
}