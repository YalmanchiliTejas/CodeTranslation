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
		int mx  = 0;
		int res = 0;
		int val[3];
		for(int i=0;i<3;i++){
			int L = 0, R = min(d[i], d[i+3])+1;
			d[i] += d[i+3];
			while(R-L>1){
				int mid = (L+R)/2;
				int lest = d[i]-2*mid;
				if(lest >= mid) L = mid;
				else            R = mid;
			}
			val[i] = L;
			val[i] = (d[i]/3);
			mx = max(mx, d[i]-3*L);
		}
		for(int i=0;i<3;i++) mx = min(mx, d[i]);
		for(int j=0;j<=100;j++){
			int tmp = mx-j;
			if(tmp < 0) continue;
			for(int i=0;i<3;i++)
				tmp += min(val[i], (d[i]-mx+j)/3);
			res = max(res, tmp);
		}
		cout << res << endl;
	}
	return 0;
}