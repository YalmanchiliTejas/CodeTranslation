#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int n,m;
	cin >> n >> m;
	if(n > m){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}
}