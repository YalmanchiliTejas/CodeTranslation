#include<bits/stdc++.h>
using namespace std;

#define int long long

// #include "debug.cpp"

int32_t main(){
	int n, x, m, i, j;
	cin >> n >> x >> m;
	if(n <= 1000000){
		int arr[n];
		arr[0] = x;
		int ans = x;
		for(i=1; i<n; i++){
			arr[i] = arr[i-1]*arr[i-1] % m;
			ans += arr[i];
		}

		cout << ans << "\n";
		return 0;
	}

	map<int, int> mp;
	int arr[1000000];
	arr[0] = x;
	mp[x] = 0;

	int cycle_length, startval, cycle_start_ind;
	for(i=1; i<n; i++){
		arr[i] = arr[i-1]*arr[i-1] % m;
		if(mp.find(arr[i]) != mp.end()){
			cycle_length = i-mp[arr[i]];
			cycle_start_ind = mp[arr[i]];
			startval = arr[i];
			break;
		}
		else{
			mp[arr[i]] = i;
		}
	}

	int ans = 0, ind = 0;
	for(i=0; i<cycle_start_ind; i++){
		ans += arr[i];
	}

	n -= cycle_start_ind+1;

	int cycle_sum = 0;
	for(i=cycle_start_ind; i<cycle_start_ind + cycle_length; i++){
		cycle_sum += arr[i];
	}

	// debug(cycle_start_ind, cycle_length, cycle_sum);

	ans += n/cycle_length * cycle_sum;
	int rem = n%cycle_length;

	for(i=cycle_start_ind; i<=cycle_start_ind+rem; i++){
		ans += arr[i];
	}

	// 492443256176507


	// print(mp);

	cout << ans << "\n";
}