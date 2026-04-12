#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	int mah = 0;
	int cnt = 0;
	rep(i,n){
		int h;
		cin >> h;
		if(h >= mah) cnt++;
		mah = max(mah,h);
	}
	cout << cnt << endl;
}