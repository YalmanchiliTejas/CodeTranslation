#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll amari = 1e9+7;
#define ben(a) a.begin(),a.end()
#define pb(a,b) a.push_back(b)

int main(){
	int n;
	cin >> n;
	int maxi = 0;
	int h;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> h;
		if(maxi <= h)sum++;

		maxi = max(h,maxi);
	}
	cout << sum << endl;
	return 0;
}