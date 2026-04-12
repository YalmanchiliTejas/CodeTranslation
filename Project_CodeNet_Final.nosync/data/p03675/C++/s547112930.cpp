#include<bits/stdc++.h>
using namespace std;


int n,a[200200];

int main(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	if (n%2==0){
		for (int i=n;i>0;i-=2) cout << a[i] << " ";
		for (int i=1;i<=n;i+=2) cout << a[i] << " ";
	}
	else{
		for (int i=n;i>0;i-=2) cout << a[i] << " ";
		for (int i=2;i<=n;i+=2) cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}