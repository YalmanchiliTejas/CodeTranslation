#include <bits/stdc++.h>
#define MOD (long long)(1E9+7)
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int n,maxi=0, x, cnt = 0;
	cin >> n;
	rep(i, n){
		cin >> x;
      	if(maxi <= x) {
        	maxi = x;
          	cnt++;
        }
	}
	cout << cnt << endl;
	
}