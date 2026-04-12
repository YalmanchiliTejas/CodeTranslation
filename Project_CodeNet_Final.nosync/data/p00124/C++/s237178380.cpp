#include<iostream>
#include<string>
using namespace std;

int main(){

	int n, max_pt, pt[10], win, lose, drow, cnt;
	string str[10];

	cnt = 0;
	while(cin >> n){
		if(n == 0) break;
		if(cnt != 0) cout << endl;
		max_pt = 0;
		for(int i=0; i<n; i++){
			win = 0;
			lose = 0;
			drow = 0;
			cin >> str[i] >> win >> lose >> drow;
			pt[i] = win * 3 + drow;
			max_pt = max(max_pt, pt[i]);
		}
	
		for(int i=max_pt; i>=0; i--){
			for(int j=0; j<n; j++){
				if(pt[j] == i) cout << str[j] << "," << pt[j] << endl;
			}
		}
		cnt++;
	}

	return 0;

}