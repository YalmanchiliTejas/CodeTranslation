#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
const int MOD = 1e9+7;
int p[MAXN];
int main() {
	string n;
	int k;
	cin >> n >> k;
	int sum = 0;
	int len = n.size();
	int n_fi = n[0] - '0';
	if(k == 1){
		for(int i = 1; i <= 9;i++){
			if(i <= n_fi){
				sum += len;
			}else{
				sum += len -1;
			}
		}
	}
	if(k == 2){
		sum = (len - 1)*(len - 2) /2 * 81;
		sum += (n_fi - 1) * 9 * (len - 1);
		for(int i = 1; i < len; i++){
			for(int j = 1; j<= 9; j++){
				string now = string (len,'0');
				now[0] = n[0];
				now[i] = j + '0';
				if(now <= n)
					sum++;
			}
		}
	}
	if(k == 3){
		sum = (len - 1) * (len - 2) * (len - 3) / 6 * 729;
		sum += (n_fi - 1) * 81 * (len - 1)*(len - 2) /2;
		for(int i = 1; i < len;i++){
			for(int j = 1; j <= 9; j++){
				for(int ii = i+1; ii < len; ii++){
					for(int jj = 1; jj <= 9; jj++){
						string now = string (len,'0');
						now[0] = n[0];
						now[i] = j+'0';
						now[ii] = jj+'0';
						if(now <= n)
						sum++;
					}
				}
			}
		}

	}
	cout << sum << endl;
	return 0;
}