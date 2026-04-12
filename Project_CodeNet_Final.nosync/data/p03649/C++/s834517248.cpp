#include <iostream>
using namespace std;

typedef long long ll;
int N;
ll A[51],B[51];

int main(){
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> A[i];
	}
	bool judge = false;
	ll ans = 0;
	while(!judge){
		ll sum = 0;
		for(int i=1;i<=N;i++){
			ans += A[i]/N;
			sum += A[i]/N;
			B[i] = A[i]/N;
			A[i] %= N;
		}
		judge = true;
		for(int i=1;i<=N;i++){
			A[i] = A[i] + sum - B[i];
			if(A[i]/N!=0) judge = false;
		}
	}
	cout << ans << endl;
}