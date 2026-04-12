#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define LL long long
LL H = 1, X, ans;
int N;
LL need[51];
LL P[51];
void solve(LL x, LL h,int r){
	if(x == 0) return;
	else if(h == x) need[r]++;
	else if(x >= (h + 1) / 2){
		ans++;
		need[r - 1]++;
		solve(x - (h + 1) / 2, (h - 3) / 2, r - 1);
	}else{
		solve(x - 1, (h - 3) / 2, r - 1);		
	}
}


int main(){
	cin >> N >> X;
	P[0] = 1;
	for(int i = 1; i <= N; i++){
		H = H * 2 + 3;
		P[i] = P[i - 1] * 2 + 1;
	}
	solve(X, H, N);
	for(int i = 0; i <= N; i++){
		ans += need[i] * P[i];
	}
	cout << ans << endl;
	return 0;
}