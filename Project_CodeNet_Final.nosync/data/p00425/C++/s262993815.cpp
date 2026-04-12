#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n;
	while(cin >> n,n){
		//dice = {u,l,r,d};
		int center = 1, dice[4] = {5,4,3,2}, res = 1;
		while(n--){
			string siji;
			cin >> siji;
			int vircen = center,virdice[4] = {0};
			memcpy(virdice,dice,sizeof(dice));
			if(siji == "North"){
				center = dice[3];
				dice[0] = vircen;
				dice[3] = 7 - vircen;
			}
			if(siji == "South"){
				center = dice[0];
				dice[0] = 7 - vircen;
				dice[3] = vircen;
			}
			if(siji == "East"){
				center = dice[1];
				dice[1] = 7 - vircen;
				dice[2] = vircen;
			}
			if(siji == "West"){
				center = dice[2];
				dice[1] = vircen;
				dice[2] = 7 - vircen;
			}
			if(siji == "Left"){
				dice[0] = virdice[2];
				dice[1] = virdice[0];
				dice[2] = virdice[3];
				dice[3] = virdice[1];
			}
			if(siji == "Right"){
				dice[0] = virdice[1];
				dice[1] = virdice[3];
				dice[2] = virdice[0];
				dice[3] = virdice[2];
			}
			//cout << center << endl;
			//for(int i=0;i<4;i++){
			//cout << dice[i];
			//}
			//cout << "\n";
			res += center;
		}
		cout << res << endl;
	}
}