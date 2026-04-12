#include <bits/stdc++.h>
#pragma optimize("O2")
#define IOS cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
using namespace std;

int A[100002];
vector<int> t(400000);
map<int, vector<int>> M;

int main(){
	IOS;
	int n, m;
	cin >> n >> m;
	if(n == m){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}