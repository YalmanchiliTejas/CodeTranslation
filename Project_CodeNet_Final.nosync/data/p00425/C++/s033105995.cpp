#include <iostream>
using namespace std;
int main(){
	int n;
	while(cin >> n,n){
		//dice = {u,l,r,d};
		int center = 1, dice[4] = {5,4,3,2}, res = 1;
		while(n--){
			string siji;
			cin >> siji;
			int tmp = center;
			if(siji == "North"){				
				center = dice[3];
				dice[0] = tmp;
				dice[3] = 7 - tmp;
			}
			if(siji == "South"){				
				center = dice[0];
				dice[0] = 7 - tmp;
				dice[3] = tmp;
			}
			if(siji == "East"){				
				center = dice[1];
				dice[1] = 7 - tmp;
				dice[2] = tmp;
			}
			if(siji == "West"){				
				center = dice[2];
				dice[1] = tmp;
				dice[2] = 7 - tmp;
			}
			if(siji == "Left"){
				tmp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[3];
				dice[3] = dice[1];
				dice[1] = tmp;
			}
			if(siji == "Right"){
				tmp = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[2];
				dice[2] = tmp;
			}
			res += center;
		}
		cout << res << endl;
	}
}