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
#define MOD 1000000007

#define IMIN INT_MIN;
#define IMAX INT_MAX;


int main(){
	int K, N;
	string S;

	cin >> N >> S >> K;
	char h = S[K-1];
	rep(i, N) {
		if (S[i] != h) cout << '*';
		else cout << S[i];
	}
	cout << endl;


	return 0;
}

