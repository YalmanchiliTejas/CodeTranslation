#include<bits/stdc++.h>
using namespace std;

long long N;
long long a[55];

//bool can(long long num){
//	long long ans = 0;
//	for(long long i = 0; i < N; i++){
//		long long cur = a[i] + num;
//		if((cur - (N - 1))%(N+1) == 0){
//			ans += (cur - (N - 1))/(N+1);
//		}else{
//			ans += (cur - (N - 1))/(N+1) + 1;
//		}
//	}
//	return ans <= num;
//}

bool can(long long num){
	long long ans = 0;
	for(long long i = 0; i < N; i++){
		long long tmp = a[i] + num - N + 1;
		if(tmp <= 0){
			continue;
		}
		if(tmp % (1 + N) == 0){
			ans += tmp / (1 + N);
		}else{
			ans += tmp / (1 + N);
			ans++;
		}
	}
	return ans <= num;
}




int main(){
	cin >> N;
	long long sumi = 0;
	for(long long i = 0; i < N; i++){
		cin >> a[i];
		sumi += a[i];
	}

	//minimum need
	//maxi need = sumi + N * N - 1;
	sumi -= N * (N - 1);

	for(long long i = max((long long)0, sumi); i <= sumi + N * (N - 1); i++){
		if(can(i)){
			cout << i << endl;
			return 0;
		}
	}

}

