#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> h(n);
	rep(i,n) cin >> h[i];
	int k = h[0];
	int counts = 0;
	rep(i,n){
		if(h[i] >= k){
			k = h[i];
			counts++;
		}
	}
	cout << counts << endl;
}