#include <bits/stdc++.h>
using namespace std;

#define is_uruu leapyear
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(a);i>(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)


 
int main()
{
	int n, a, to, A[200005];
	cin >> n;
	
	FOR(i, 0, n){
		cin >> a;
		if(i%2 == n%2){
			to = n/2+(i+1)/2;
		} 
		else {
			to = n/2-(i+1)/2;
		}
		A[to] = a;
	}
	
	FOR(i, 0, n){
		printf("%d%c", A[i], i==n-1?'\n':' ');
	}
	
	return 0;
}