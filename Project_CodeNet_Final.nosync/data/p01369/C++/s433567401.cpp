#include <iostream>
#include <string>
using namespace std;

int main(){
	string n;
	string r = "yuiophjklnm";
	string l = "qwertasdfgzxcvb";
	while (1){
		cin >> n;
		if (n[0] == '#') break;
		int cnt = 0;
		int hand = 2; //0:right 1:left 2:unknown
		int flg;
		for (int i = 0; i < n.length(); i++){
			flg = 0;
			//??????????????£???????????´???
			if (hand == 0){
				for (int j = 0; j < r.length();j++){
					if (n[i] == r[j]){
						flg = 1;
						break;
					}
				}
				if (flg == 0){
					hand = 1;
					cnt++;
				}
			}
			//????????\???????????£???????????´???
			else{
				for (int j = 0; j < l.length(); j++){
					if (n[i] == l[j]){
						flg = 1;
						break;
					}
				}
				if (flg == 0){
					if (hand == 2){
						hand = 0;
						continue;
					}
					hand = 0;
					cnt++;
				}
				if (hand == 2){
					hand = 1;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}