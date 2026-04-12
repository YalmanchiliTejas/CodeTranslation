#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin >> n >> m;
	if(m>=n){
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}