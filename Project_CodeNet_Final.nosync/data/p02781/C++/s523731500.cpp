#include<bits/stdc++.h>
using namespace std;

int main() {
	
	string n;
	int k;
	cin >> n >> k;
	int m = n.size();
	vector<vector<vector<int>>> dp(m,vector<vector<int>>(2,vector<int>(k+1)));
	dp.at(0).at(1).at(1) = n.at(0)-1-'0';
	dp.at(0).at(1).at(0) = 1;
	dp.at(0).at(0).at(1) = 1;
	for(int i=1; i<m; i++){
		for(int j=0; j<k+1; j++){
			if(j)dp.at(i).at(1).at(j) += 9*dp.at(i-1).at(1).at(j-1);
			dp.at(i).at(1).at(j) += dp.at(i-1).at(1).at(j);
			if(n.at(i)>'0'){
				if(j)dp.at(i).at(1).at(j) += ((n.at(i))-1-'0') * dp.at(i-1).at(0).at(j-1);
				dp.at(i).at(1).at(j) += dp.at(i-1).at(0).at(j);
			}
			if(n.at(i)>'0'){
				if(j)dp.at(i).at(0).at(j) += dp.at(i-1).at(0).at(j-1);
			}
			else{
				dp.at(i).at(0).at(j) += dp.at(i-1).at(0).at(j);
			}
		}
	}
	cout << dp.at(m-1).at(1).at(k)+dp.at(m-1).at(0).at(k) << endl;
	
}