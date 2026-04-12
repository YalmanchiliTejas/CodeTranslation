#include <iostream>

using namespace std;

int main(){

	int d[6];
	while(true){
		int sum = 0;
		for(int i=0;i<6;i++){
			cin >> d[i];
			sum += d[i];
		}
		if(sum == 0) break;
		int res = 0;
		int val[3];
		int mx = 3;
		for(int i=0;i<3;i++){
			d[i] += d[i+3];
			val[i] = d[i]/3;
			mx = min(mx, d[i]);
		}
		for(int j=0;j<=mx;j++){
			int tmp = j;
			if(tmp < 0) continue;
			for(int i=0;i<3;i++)
				tmp += (d[i]-j)/3;
			res = max(res, tmp);
		}
		cout << res << endl;
	}
	return 0;
}