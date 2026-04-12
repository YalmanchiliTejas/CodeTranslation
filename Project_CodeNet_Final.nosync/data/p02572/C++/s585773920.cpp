#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

#define llong long long
#define rep(i,l,n) for(llong (i)=(l);(i)<(n);(i++))
#define _min(a,b) ((a)<(b)?(a):(b))
#define _max(a,b) ((a)>(b)?(a):(b))
#define _abs(a) ((a)>0?(a):(-(a)))

using namespace std;

#define P (1000000007)

int main(){
	int N;
	cin >> N;
	llong A[N];
	rep(i,0,N) cin >> A[i];
	
	llong ans = 0;
	rep(i,0,N) ans = (ans+A[i])%P;
	ans = (ans*ans)%P;
	rep(i,0,N){
		ans = (ans-A[i]*A[i])%P;
		while( ans < 0 ) ans+=P;
	}
	ans = (ans*500000004)%P;
	cout << ans;
	
	return 0;
}
