//tenka1_2018_c.cpp
//Sat Oct 27 20:32:23 2018

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	ll n;
	cin >> n;
	ll a[n];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);

	ll left = a[0];
	ll right = a[0];
	ll ans = 0;
	int flag = 1; //1なら大きい方から足す。
	ll larger = n-1;
	ll smaller = 1;
	while (larger>=smaller){
		if (flag == 1){
			ll temp = a[larger]-left;
			ans = ans + temp;
			left = a[larger];
			larger--;
			temp = a[larger]-right;
			ans = ans + temp;
			right = a[larger];
			larger--;
			flag = 0;
		}else {
			ll temp = left - a[smaller];
			ans = ans + temp;
			left = a[smaller];
			smaller++;
			temp = right - a[smaller];
			ans = ans + temp;
			right = a[smaller];
			smaller++;
			flag = 1;
		}
	}
	if (larger == smaller){
		ll temp = 0;
		if (a[larger] > left){
			temp = a[larger] - left;
		}else {
			temp = left - a[larger];
		}
		ans = ans + temp;
	}

	left = a[n-1];
	right = a[n-1];
	ll ans2 = 0;
	flag = 0; //1なら大きい方から足す。
	larger = n-2;
	smaller = 0;
	while (larger>=smaller){
		if (flag == 1){
			ll temp = a[larger]-left;
			ans2 = ans2 + temp;
			left = a[larger];
			larger--;
			temp = a[larger]-right;
			ans2 = ans2 + temp;
			right = a[larger];
			larger--;
			flag = 0;
		}else {
			ll temp = left - a[smaller];
			ans2 = ans2 + temp;
			left = a[smaller];
			smaller++;
			temp = right - a[smaller];
			ans2 = ans2 + temp;
			right = a[smaller];
			smaller++;
			flag = 1;
		}
	}
	if (larger == smaller){
		ll temp = 0;
		if (a[larger] > left){
			temp = a[larger] - left;
		}else {
			temp = left - a[larger];
		}
		ans2 = ans2 + temp;
	}

	if (ans > ans2){
		cout << ans << endl;
	}else{
		cout << ans2 << endl;
	}
}