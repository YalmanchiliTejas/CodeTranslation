#include <bits/stdc++.h>
using namespace std;

#define pb         push_back

typedef long long ll;
const ll INF = 1000000000ll;
const ll MOD = 1000000007ll;
const double EPS = 1e-8;

int main(void) {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int h, w;
	cin >> h >> w;

	int cur = 0;
	for(int i=0; i<h; i++){
		string t;
		cin >> t;

		int next = 0;
		for(int j=0; j<w; j++){
			if(t[j] == '#'){
				next = j;
				if(j < cur){
					puts("Impossible");
					return 0;
				}
			}
		}
		cur = next;
	}
	puts("Possible");

	return 0;
}
