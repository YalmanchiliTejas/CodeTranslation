#include<cstdio>
#include<cmath>
#include<climits>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<list>
#include<map>
#include<vector>

using namespace std;


#define rep(i,n) for(int i=0; i<n; i++)
#define rept(i,a,b) for(int i=a; i<b; i++)
#define ll long long

#define IMIN INT_MIN;
#define IMAX INT_MAX;


int main(){
	int N;
	cin >> N;
	vector<int> H(N);
	rep(i, N) cin >> H[i];


	int cnt = 1;
	int st = H[0];

	rept(i, 1, N) {
		if (st <= H[i]) {
			cnt++;
			st = H[i];
		}
		else continue;
	}

	cout << cnt << endl;




	return 0;
}

