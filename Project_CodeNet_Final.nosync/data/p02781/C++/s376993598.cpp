#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
const int inf = 1001001000;
const long long int Inf = 1001001001001001000;

void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}



int main()
{
	string s;
	int k;
	cin >> s;
	cin >> k;
	int n = s.size();
	vector<vector<vector<long long int>>> dp(n+1, vector<vector<long long int>>(2, vector<long long int>(5, 0)));
	dp[0][0][0] = 1;
	rep(i, n)
	{
		int D = s[i] - '0';
		rep(j, 2)
		{
			rep(k,5){
				for (int d = 0; d <= (j ? 9 : D);d++){
					if (d == 0){
						// cout << "test" << endl;
						dp[i + 1][j || (d < D)][k] += dp[i][j][k];
					}
					else{
						// cout << "test2" << endl;
						dp[i + 1][j || (d < D)][min(k + 1, 4)] += dp[i][j][k];
					}
						
				}
			}
		}
	}
	cout << dp[n][0][k] + dp[n][1][k] << endl;
	return 0;
}