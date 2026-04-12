#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	int dice[5];
	string s;
	while(cin >> n && n){
		int ans = 1;
		dice[0] = 1; dice[1] = 5; dice[2] = 2; dice[3] = 3; dice[4] = 4;
		for(int i = 0; i < n; i++){
			cin >> s;
			if(s[0] == 'S'){
				int temp = dice[0];
				dice[0] = dice[1];
				dice[1] = 7 - temp;
				dice[2] = temp; 
			}
			if(s[0] == 'N'){
				int temp = dice[0];
				dice[0] = dice[2];
				dice[2] = 7 - temp;
				dice[1] = temp;
			}
			if(s[0] == 'W'){
				int temp = dice[0];
				dice[0] = dice[3];
				dice[3] = 7 - temp;
				dice[4] = temp;
			}
			if(s[0] == 'E'){
				int temp = dice[0];
				dice[0] = dice[4];
				dice[4] = 7 - temp;
				dice[3] = temp;	
			}
			if(s[0] == 'L'){
				int temp;
				temp = dice[2];
				dice[2] = dice[4];
				dice[4] = dice[1];
				dice[1] = dice[3];
				dice[3] = temp;
			}
			if(s[0] == 'R'){
				int temp = dice[3];
				dice[3] = dice[1];
				dice[1] = dice[4];
				dice[4] = dice[2];
				dice[2] = temp;
			}
			ans += dice[0];
		}
		cout << ans << endl;
	}
}