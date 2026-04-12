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
	for (int i=0;i<a.size();i++){
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

int LIS(vector<int> a){
	deque<int> dp;
	for (int i = 0; i< a.size(); i++){
		int p = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
		if (p == 0){
			dp.push_front(a[i]);
		}
		else
			dp[p - 1] = a[i];
	}
	return dp.size();
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	cout << LIS(a) << endl;

	return 0;
}

