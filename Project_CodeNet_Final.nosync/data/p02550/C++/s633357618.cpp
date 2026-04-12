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

int main(){
	llong N,X,M;
	cin >> N >> X >> M;
	int first[M];
	llong first_sum[M];
	rep(i,0,M){
		first[i] = -1;
		first_sum[i] = 0;
	}
	
	llong ans=0;
	if( M < N ){
		int roop;
		llong roop_ans;
		rep(i,0,N){
			if( first[X]>=0 ){
				roop = i-first[X];
				roop_ans = ans-first_sum[X];
				break;
			}else{
				first[X] = i;
				first_sum[X] = ans;
				ans += X;
			}
			X = (X*X)%M;
		}
		ans += roop_ans*((N-first[X])/roop - 1);
		N = (N-first[X])%roop;
	}
	rep(i,0,N){
		ans += X;
		X = (X*X)%M;
	}
	cout << ans;
}
