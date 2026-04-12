#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <list>
#include <deque>
#include <math.h>
using namespace std;

typedef pair<int, int> P;
#define ll long long
#define int ll
#define INF (1LL<<30)

int N, M;
int a[8];
int d[8+1][8+1];

signed main(){
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int s, t;
		cin >> s >> t;
		d[s][t] = d[t][s] = 1;
	}

	int r = 0;
	for (int i = 0; i < N; i++) a[i] = i + 1;
	do{

		if (a[0] != 1) continue;
		bool f = true;
		for (int i = 0; i < N-1; i++){
			if (d[a[i]][a[i + 1]] == 0) f = false;
		}
		if (f == false) continue;
		r++;

	} while (next_permutation(a, a + N));

	cout << r << endl;

	return 0;
}
