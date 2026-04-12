#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n != 0){
		int s[n];
		for(int i = 0;i < n; i++){
			cin >> s[i];
		}
		sort(s,s+n);
		int tmp = 0;
		for(int i = 1;i < n-1; i++){
			tmp += s[i];
		}
		cout << tmp / (n-2) << endl;
		cin >> n;
	}
	return 0;
}
