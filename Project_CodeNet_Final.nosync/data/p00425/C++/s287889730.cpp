#include<iostream>
#include<string>

using namespace std;

int main(){
	int i, n, dice[7], ans = 1, damy, damy2;
	string word;
	
	while(1){
		
		for(i = 1; i <= 6; i ++){
			dice[i] = i;
		}
		ans = 1;
		cin >> n;
		if(n == 0) break;

		for(i = 0; i < n; i ++){
			cin >> word;
			if(word == "North"){
				damy = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[6];
				damy2 = dice[5];
				dice[5] = damy;
				dice[6] = damy2;
				ans += dice[1];
			}
			else if(word == "East"){
				damy = dice[1];
				dice[1] = dice[4];
				damy2 = dice[3];
				dice[3] = damy;
				dice[4] = dice[6];
				dice[6] = damy2;
				ans += dice[1];
			}
			else if(word == "South"){
				damy = dice[1];
				damy2 = dice[2];
				dice[1] = dice[5];
				dice[2] = damy;
				dice[5] = dice[6];
				dice[6] = damy2;
				ans += dice[1];
			}
			else if(word == "West"){
				damy = dice[1];
				damy2 = dice[4];
				dice[1] = dice[3];
				dice[3] = dice[6];
				dice[4] = damy;
				dice[6] = damy2;
				ans += dice[1];
			}
			else if(word == "Right"){
				damy = dice[2];
				damy2 =dice[4];
				dice[2] = dice[3];
				dice[3] = dice[5];
				dice[4] = damy;
				dice[5] = damy2;
				ans += dice[1];
			}
			else if(word == "Left"){
				damy = dice[2];
				damy2 = dice[3];
				dice[2] = dice[4];
				dice[3] = damy;
				dice[4] = dice[5];
				dice[5] = damy2;
				ans += dice[1];
			}
		}

		cout << ans << endl;
	}

	return 0;
}