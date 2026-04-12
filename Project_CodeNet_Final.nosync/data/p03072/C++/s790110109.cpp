#include <bits/stdc++.h>
#define REP(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define REPR(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define FOR(i, m, n) for(int (i) = (m); (i) < (n); (i)++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main()
{
	int N;
	int count = 1;
	int j = 0;
	cin >> N;
	int H[N];
	REP(i, N) cin >> H[i];

	REP(i, N){
		while(H[i] - H[j] >= 0){
			j++;
			if(j == i) {
				count++;
				break;
			}
		}
		j = 0;
	}
	cout << count << endl;
}