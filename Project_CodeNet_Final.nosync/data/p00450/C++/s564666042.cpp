#include<cstdio>
#include <iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<list>
#include<set>
#include<numeric>

#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int board[100010];

int main()
{
	int N;  
	while (1) {
		cin >> N;
		if (N == 0)break;
		int ans = 0;

		for (int i = 0; i < N; i++) {
			cin >> board[i];
			if (i % 2 == 1) {
				for (int j = i - 1; j >= 0; j--) {
					if (board[j] == board[i])break;
					board[j] = board[i];
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (board[i] == 0)ans++;
		}
		cout << ans << endl;
	}
	return 0;
}