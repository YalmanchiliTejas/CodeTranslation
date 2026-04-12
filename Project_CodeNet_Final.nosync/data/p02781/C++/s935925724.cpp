#include<iostream>
using namespace std;
long long int dp1[101][4], dp0[101][4];
int main() {

	string n;
	int  k;
	cin >> n;
	cin >> k;
	int i, j;

    dp0[0][0] = 1;
	dp0[0][1] = n[0] - '0' - 1;
	dp1[0][1] = 1;
	for (i = 1; i < n.size(); i++) {
      dp0[i][0] = 1;
      dp1[i][0] = 0;
		for (j = 1; j < 4; j++) {
			dp0[i][j] = dp0[i - 1][j] + dp0[i - 1][j - 1] * 9;
			if (n[i] != '0')dp0[i][j] = dp0[i][j] + dp1[i - 1][j] + dp1[i - 1][j - 1] * (n[i] - '0' - 1);
			if (n[i] == '0') {
				dp1[i][j] = dp1[i - 1][j];
			}
			else {
				dp1[i][j] = dp1[i - 1][j - 1];
			}
		}
	}
  //for(i = 0;i<n.size();i++){
  //  cout << dp0[i][2] << ' ' <<dp0[i][3] << ' ' << dp1[i][3] << endl;
  //}
	//cout << dp0[0][k] + dp1[0][k] << endl;
  //cout << dp0[0][1] << ' ' << dp1[0][1] << ' ' << dp0[1][1] << ' ' << dp1[1][1] << ' ' << dp0[2][1] << ' ' << dp1[2][1] << endl;
	cout << (dp0[n.size() - 1][k] + dp1[n.size() - 1][k]) << endl;
	return 0;

}