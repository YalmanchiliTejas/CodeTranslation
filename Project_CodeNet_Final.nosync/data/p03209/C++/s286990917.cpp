#include <iostream>
using namespace std;

int n;
long x, dp[51];

long a(int n){return (1L << (n+2)) - 3;}
long b(int n){return (1L << (n+1)) - 1;}

long dps(int n, long x){
	if (x >= a(n)) return b(n);
	else if (x == 1) return 0;
	else if (1 < x && x <= a(n-1)+1) return dps(n-1, x-1);
	else if (x == a(n-1)+2) return b(n-1) + 1;
	else return b(n-1) + dps(n-1, x-a(n-1)-2) + 1;
}

int main(){
	cin >> n >> x;
	cout << dps(n, x);
}