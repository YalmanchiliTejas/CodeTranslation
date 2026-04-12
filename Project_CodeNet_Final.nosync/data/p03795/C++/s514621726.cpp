#include<iostream>
#include<string>
#include<utility>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main(void) {
	int n; cin >> n;
	cout << n * 800 - (n / 15*200) << endl;
	return 0;
}