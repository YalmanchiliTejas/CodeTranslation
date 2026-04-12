#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0; i < n; i++)



int main() {

	vector<char>N(3);
	rep(i, 3) {
		cin >> N[i];
		if (i != 0) {
			if (N[i - 1] != N[i]){
				cout << "Yes" << endl;
				return 0;
			}

		}
	}
	
	cout <<"No"<< endl;
}
