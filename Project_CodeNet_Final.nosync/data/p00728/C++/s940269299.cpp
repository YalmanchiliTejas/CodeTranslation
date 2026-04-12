#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int s[100];
	int sum;
	
	cin >> n;
	while(n > 2){
		for(int i=0; i<n; ++i){
			cin >> s[i];
		}
		
		sort(s, s+n);
		
		sum=0;
		for(int i=1; i<(n-1); ++i){
			sum+=s[i];
		}
		
		cout << sum/(n-2) << endl;
		cin >> n;
	}
	
	return 0;
}