#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <functional>
using namespace std;

typedef pair<int, int> P;
const int INF = 1e+9;

int main() {
	int n;
	while(cin >> n && n){
		int s, prev = 0, ans = 0, m[100001] = {0}, r = 0, l = 0;
		scanf("%d", &prev);
		l = prev & 1;
		m[r] = 1;
		for(int i = 2; i <= n; ++i){
			scanf("%d", &s);
			
			if(prev == s){
				m[r]++;
			}
			else{
				if(i % 2){
					m[++r] = 1;
				}
				else{
					if(r == 0){
						m[r]++;
						l ^= 1;
					}
					else{
						m[r - 1] += m[r] + 1;
						r--;
					}
				}
			}
			prev = s;
		}
		if(l == 1){
			for(int i = 1; i <= r; i += 2)
				ans += m[i];
		}
		else{
			for(int i = 0; i <= r; i += 2)
				ans += m[i];
		}
		cout << ans << endl;
	}
	
	return 0;
}