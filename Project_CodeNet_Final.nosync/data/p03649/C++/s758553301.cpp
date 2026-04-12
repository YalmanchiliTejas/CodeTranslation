#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n;
	cin >> n;
	LL a[50];
	multiset<LL> b;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]++;
		b.insert(-a[i]);
	}
	LL c = 0;
	LL num = 0;
	while((-*b.begin()) - c >= (n+1)){
		LL k = -*b.begin();
		b.erase(b.begin());
		LL r = (k-c) / (n+1);
		c -= r;
		k -= r*(n+1);
		num += r;
		//cout << r << endl;
		b.insert(-k);
	}
	cout << num << endl;
}
