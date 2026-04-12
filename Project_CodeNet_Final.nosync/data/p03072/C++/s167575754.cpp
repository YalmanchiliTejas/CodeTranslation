#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<int> h(n);
	rep(i,n) cin >> h[i];
	
	int res = 1;
	int high = h[0];
	
	rep(i,n-1){
		if(h[i+1] >= high){
			res++;
			high = h[i+1];
		}
	}
	
	cout << res << endl;
	
	return 0;
}