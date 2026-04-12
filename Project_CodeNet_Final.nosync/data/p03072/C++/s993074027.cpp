#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
	
	int n;
	cin >> n;
	vector <int> a;
	
	for(int i=0 ; i< n; i++){
		int t;
		cin >> t;
		a.push_back(t);
	}

	int m = a[0];
	int c= 0;
	for(int i=0; i < n; i++ ){
		if(a[i] >= m){
			c++;
		}
		m = max(m,a[i]);
	}

	cout << c;


	return 0;

}