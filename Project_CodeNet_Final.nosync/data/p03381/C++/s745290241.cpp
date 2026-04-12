#include<bits/stdc++.h>

#define INF 1000000007
#define LINF 1000000000000000007

using namespace std;

typedef long long Int;
typedef pair<Int, Int> P;

Int gcd(Int x, Int y){
	if(y == 0)
		return x;
	return gcd(y, x % y);
}

Int lcm(Int x, Int y){
	return x * y / gcd(x, y);
}

bool sosuu(int x){
	bool b = 1;
	if(x == 1) b = 0;
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0) {
			b = 0;
			break;
		}
	}
	return b;
}

int n, x[200000], a[200000];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i];
		a[i] = x[i];
	}
	sort(x, x+ n);
	int l = x[n/2-1], r = x[n/2];
	
	for(int i = 0; i < n; i++){
		if(a[i] <= l) cout << r << endl;
		else cout << l << endl;
	}
	
	return 0;
}