#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int n, k;
int a[100005], b[100005];
int solve(int shift, int size, int pos){
	if(size == 0) return 1;
	int mid = (2*shift + a[size] - 1)/2;
	if(pos == shift) return 0;
	else if(pos < mid) return solve(shift + 1, size - 1, pos);
	else if(pos == mid) return b[size - 1] + 1;
	else if(pos < shift + a[size] - 1)return b[size - 1] + 1 + solve(mid + 1, size - 1, pos);
	else return b[size];
}
signed main(){
	a[0] = 1, b[0] = 1;
	for(int i = 1 ; i <= 50 ; i ++)
		a[i] = 2*a[i - 1] + 3, b[i] = 2*b[i - 1] + 1;
	
	cin >> n >> k;
	//cout << a[n] << " " << b[n] << endl;
	cout << solve(1, n, k);
}
