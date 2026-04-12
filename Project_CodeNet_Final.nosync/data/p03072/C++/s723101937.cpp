#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i=0;i<int(n);i++)

int main(){
	int n; cin >> n;
	vector<int> h(n);
	forn(i, n){
		cin >> h[i];
	}
	int cont = 0;
	for(int i=n-1;i>=0;i--){
		int flag = 0;
		for(int j=0;j<i;j++){
			if(h[j] > h[i]){
				flag = 1;
				break;
			}
		}
		if(!flag) cont++;
	}
	cout << cont << endl;
}
