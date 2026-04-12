#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	while(true){
		int n[6] = { 0 };
		int sum = 0;
		for(int i = 0; i < 6; ++i){
			cin >> n[i];
			sum += n[i];
		}
		if(sum == 0){ break; }
		n[0] += n[3];
		n[1] += n[4];
		n[2] += n[5];
		int answer = 0;
		for(int r = 0; r <= 2; ++r){
			int a = min(n[0], min(n[1], n[2]));
			if(a < r){ break; }
			int tmp = a - r;
			tmp += (n[0] - (a - r)) / 3;
			tmp += (n[1] - (a - r)) / 3;
			tmp += (n[2] - (a - r)) / 3;
			answer = max(tmp, answer);
		}
		cout << answer << endl;
	}
	return 0;
}