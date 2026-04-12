#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void test(vector<int> &a){
	ll dp[a.size()][a.size()];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < a.size(); i++){
		dp[i][i] = a[i];
	}
	for(int i = a.size()-2; i >= 0; i--){
		for(int j = i + 1; j < a.size(); j++){
			dp[i][j] = max(a[i] - dp[i+1][j] , a[j] - dp[i][j-1]);
		}
	}
	cout << dp[0][a.size()-1] << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("/home/afzalrao/Desktop/Academics/2nd Year/3rd Sem/ESO207/CP/Text Files/input.txt", "r", stdin);
	freopen("/home/afzalrao/Desktop/Academics/2nd Year/3rd Sem/ESO207/CP/Text Files/output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	test(a);
	return 0;
}