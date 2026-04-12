#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string list[] = { "North","East","West","South","Right","Left" };
enum{ UE, TEMAE, MIGI };

int main() {
	
	int n;
	while (cin >> n, n!=0){
		int dice[3] = { 1, 2, 3 };
		int score = 1;

		for (int i = 0; i < n; ++i){
			string s;
			cin >> s;
			
			if (s == list[0]){
				int ue_tmp;
				ue_tmp = dice[UE];
				dice[UE] = dice[TEMAE];
				dice[TEMAE] = 7 - ue_tmp;
			}
			if (s == list[1]){
				int migi_tmp = dice[MIGI];
				dice[MIGI] = dice[UE];
				dice[UE] = 7 - migi_tmp;
			}
			
			if (s == list[2]){
				int ue_tmp = dice[UE];
				dice[UE] = dice[MIGI];
				dice[MIGI] = 7 - ue_tmp;
			}
			if (s == list[3]){
				int temae_tmp = dice[TEMAE];
				dice[TEMAE] = dice[UE];
				dice[UE] = 7 - temae_tmp;
				// 手前 => 上から
				// 上　=> 手前のうら
			}
			if (s == list[4]){
				int temae_tmp = dice[TEMAE];
				dice[TEMAE] = dice[MIGI];
				dice[MIGI] = 7 - temae_tmp;
			}
			if (s == list[5]){
				int migi_tmp = dice[MIGI];
				dice[MIGI] = dice[TEMAE];
				dice[TEMAE] = 7 - migi_tmp;
			}
			score += dice[UE];
		}

		cout << score << endl;

	}

	return 0;
}