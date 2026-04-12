#include <bits/stdc++.h>
using namespace std;

long long binary(long long level, long long obj){
	long long mid = powl(2, level-1)*4-1;
	if(obj == mid){
		return powl(2, level);
	}else if(obj == 2*mid-1){
		return 2*(powl(2, level) - 1) + 1;
	}else if(obj == 0){
		return 0;
	}else if(obj > mid) {
		obj -= mid;
		return powl(2, level) + binary(level - 1, obj);
	}else if(obj < mid){
		--obj;
		return binary(level - 1, obj);
	}
}

int main(){
	long long n, x; cin >> n >> x;

	cout << binary(n, x) << endl;
}
