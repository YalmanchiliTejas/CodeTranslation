#include<iostream>
using namespace std;

int main(){
	while(1){
		int maxnum = -1, maxidx = 0;
		int s1, s2;
		cin >> s1 >> s2;
		if(s1 == 0 && s2 == 0) break;
		maxnum = s1 + s2;
		for(int i = 1;i <= 4;i++){
			cin >> s1 >> s2;
			if(s1 + s2 > maxnum){
				maxnum = s1 + s2;
				maxidx = i;
			}
		}
		cout << "ABCDE"[maxidx] << ' ' << maxnum << endl;
	}
	
	return 0;
}