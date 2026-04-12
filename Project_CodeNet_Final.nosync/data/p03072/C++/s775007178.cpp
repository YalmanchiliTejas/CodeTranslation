#include <bits/stdc++.h>
#define ld long double
#define int long long
using namespace std;
const int N = 1e5 + 50;
const int mod = 1e9 + 7;
const int inf = 1e17;
int Dx[] = {0, 1, -1, 0, -1, 1, 1, -1};
int Dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = 1;
	for(int i = 1; i < n; i++){
		bool ok = true;
		for(int j = 0; j < i; j++){
			if(arr[j] > arr[i]){
				ok = false;
				break;
			}
		}
		if(ok){
			ans++;
		}
	}
	cout << ans;
}