#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<set>
#include<map>

using namespace std;


int N;
int c[100000];

int main() {
	while (cin >> N, N)
	{
		if (N == 0) break;

		for (int i = 0; i < N; i++) {
			cin >> c[i];
		}

		int ans = 0;
		int ren[100000]; ren[0] = 0;
		int k = 0;
		int last = c[0];
		for (int i = 0; i < N; i++) {
			if (i % 2 == 1) {
				if (last != c[i]) {
					if (c[i] == 0) {
						ans += ren[k];						
					}
					else {
						ans -= ren[k];
					}

					if (k > 0) {
						ren[k - 1] += ren[k];
						k--;
					}					
				}
				ren[k]++;
			}
			else {
				if (last == c[i]) {
					ren[k]++;
				}
				else {
					k++;
					ren[k] = 1;
				}
			}

			if (c[i] == 0) {
				ans++;
			}

			last = c[i];
		}


		cout << ans << endl;
	}

	return 0;
}


