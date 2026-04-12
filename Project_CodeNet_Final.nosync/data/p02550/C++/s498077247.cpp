#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N, X, M;
	cin >> N >> X >> M;
	int chk[M];
	for(int i=0;i<M;i++){
		chk[i] = 0;
	}
	chk[X]++;
	long long ans = 0;
	ans += X;
	N--;
	long long tmp = X;
	while(N > 0 && tmp != 0){
		tmp = tmp * tmp;
		tmp %= M;
		if(chk[tmp] == 2){
			//cout << tmp << endl;
			long long sum = 0, cnt = 0;
			for(int i=0;i<M;i++){
				if(chk[i] > 1){
					sum += i;
					cnt++;
				}
				chk[i]++;
			}
			ans += sum * (N / cnt);
			N %= cnt;
		}
		if(N > 0){
			N--;
			ans += tmp;
			chk[tmp]++;
		}
		// cout << tmp << ":" << ans << endl;
	}
	// while(N > 0 && tmp != 0){
	// 	tmp = modmul(tmp, tmp);
	// 	if(tmp == 1){
	// 		ans += N;
	// 		N = 0;
	// 	}
	// 	if(N > 0){
	// 		N--;
	// 		ans += tmp;
	// 		chk[tmp]++;
	// 	}
	// }
	cout << ans << endl;
}