//abc115_d.cpp
//Sat May 11 19:24:48 2019

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	ll n,x;
	cin >> n >> x;

	x--;

	ll p = 1;
	ll b = 0;
	for (int i=1;i<=n;i++){
		p = 2*p+1;
		b = 2*b+2;
	}

	ll start = 0;
	ll end = p+b-1;
	ll ans = p;
	ll change = (p-1)/2;
	ll mid = 0;
	for (int i=0;i<n;i++){
		mid = start+(end-start)/2;
		if (x==mid){
			cout << ans-change << endl;
			return 0;
		}else if (x<mid){
			ans = ans - change - 1;
			start++;
			end = mid-1;
		}else{
			start = mid+1;
			end--;
		}
		change = (change-1)/2;
	}

	if (x < mid-1){
		ans--;
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}