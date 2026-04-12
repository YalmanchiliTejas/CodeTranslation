#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <math.h>

#define PREP(i, m, n) for(int i = m; i < n; i++)
#define MREP(i, m, n) for(int i = m - 1; i >= n; i--)

#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define rev(v) v.rbegin(), v.rend()
#define prime first
#define weight second
#define MP make_pair
#define PB push_back

using namespace std;

int main(){
	int n = 0;
	while(cin >> n && n != 0){
		map<int, int> ev;
		int max = -1, min = 1001;
		
		rep(i, n){
			int s = 0;
			cin >> s;

			if(s > max) max = s;
			if(s < min) min = s;

			if(ev.find(s) != ev.end()) ev[s]++;
			else ev[s] = 1;
		}

		ev[max]--;
		ev[min]--;

		int result = 0, factor = 0;
		
		for(map<int, int>::iterator it = ev.begin(); it != ev.end(); it++){
			rep(i, it->second){
				result += it->first;
				factor++;
			}
		}

		cout << result / factor << endl;
	}
	

	return 0;
}