//chiragjn
#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define gibe_de_fast_io_b0ss ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll mod = 1e9 + 7;
const ll INF = 0x7FFFFFFFFFFFFFFF/2;
ll arr[3001];
ll csum[3001] = {0};
ll cache[3001][3001];

ll recur(int i, int j) {
	if(cache[i][j] != -1) {
		return cache[i][j];
	}
	if(i == j) {
		cache[i][j] = arr[i];
	}
	else {
		cache[i][j] = max(arr[i] + (csum[j] - csum[i]) - recur(i + 1, j),
		                  arr[j] + (csum[j - 1] - csum[i - 1]) - recur(i, j - 1));
	}
	// cout<<i<<" "<<j<<" "<<cache[i][j]<<endl;
	return cache[i][j];
}

int main(){
    gibe_de_fast_io_b0ss;
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) {
    	cin>>arr[i];
    	csum[i] = csum[i - 1] + arr[i];
    }
    for(int i = 0; i <= n; i++) {
    	for(int j = 0; j <= n; j++) {
    		cache[i][j] = -1;
    	}
    }
    ll first = recur(1, n);
    ll second = csum[n] - first;
    cout<<first - second;
    return 0;
}
