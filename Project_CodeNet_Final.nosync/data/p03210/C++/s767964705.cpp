#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<map>

#define ipair pair<int,int>
#define rep(n) for(int i=0;i<n;i++)

using namespace std;

typedef long long int lli;
typedef vector<int> vi;

int main() {
	int n;

	cin >> n;

	if (n == 3 || n == 5 || n == 7)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}