#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n;
	while(cin >> n,n){
		//dice = {u,l,r,d};
		int dice[5] = {5,4,3,2,1}, res = 1;
		while(n--){
			string siji;
			cin >> siji;
			int virdice[5] = {0};
			memcpy(virdice,dice,sizeof(dice));
			if(siji == "North" || siji == "South"){
				int zero = virdice[4], three = 7 - virdice[4];
				dice[4] = siji=="North"?dice[3]:dice[0];
				dice[0] = siji=="North"?zero:three;
				dice[3] = siji=="North"?three:zero;
			}
			if(siji == "East" || siji == "West"){
				int one = 7 - virdice[4],two = virdice[4];
				dice[4] = siji=="East"?dice[1]:dice[2];
				dice[1] = siji=="East"?one:two;
				dice[2] = siji=="East"?two:one;
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
			res += dice[4];
		}
		cout << res << endl;
	}
}