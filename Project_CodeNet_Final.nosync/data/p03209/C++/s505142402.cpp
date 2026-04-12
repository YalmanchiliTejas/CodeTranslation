#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll N, X, ans = 0;
	cin >> N >> X;
	ll two[N+2];
	two[0] = 1;
	for(int i=1; i<N+2; i++){
		two[i] = two[i-1]*2;
	}
	while(N >= 0){
		if(X == 2*two[N+1] - 3){
			ans += two[N+1] - 1;
			cout << ans << endl;
			return 0;
		}else if(X > two[N+1]-1){
			ans += two[N];
			X = X - two[N+1] + 1;
			N--;
		}else if(X == two[N+1]-1){
			ans += two[N];
			cout << ans << endl;
			return 0;
		}else if(X == 0){
			cout << ans << endl;
			return 0;
		}else{
			X--;
			N--;
		}
	}
	cout << ans << endl;
	return 0;
}