#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	string S;
	cin >> S;
	for(int i = 0; i < S.size() - 1; i++){
		if(S.substr(i,2) == "AC") {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

}








