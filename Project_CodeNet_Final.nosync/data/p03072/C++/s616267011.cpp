#include<bits/stdc++.h>
#define ll long long
#define w cout 
#define e endl

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n];
	int maxsofar = -1 , ans = 0;
	for(int i = 0 ; i < n ;i ++ ) {
		cin >> arr[i];
		if(arr[i] >= maxsofar) {
			ans++;
		}
		maxsofar = max(maxsofar , arr[i]);
	}
	w << ans;
}
