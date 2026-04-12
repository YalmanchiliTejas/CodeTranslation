#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	int h[20];
	int ans = 0;
	int m = 0;
	for(int i = 0; i < n; i++){
		cin >> h[i];
		if(!i)ans++;
		else if(h[i] >= m)ans++;
		m = max(h[i], m);
	}
	cout << ans << endl;
    return 0;
}