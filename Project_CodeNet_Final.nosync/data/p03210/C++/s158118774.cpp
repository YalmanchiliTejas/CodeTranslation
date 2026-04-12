#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define SORT(v, n) sort(v, v+n);
#define SSORT(v, n) sort(v, v+n, greater<int>())

int main(){
	int x;
	cin >> x;
	if(x == 7 || x == 5 || x == 3) cout << "YES" << endl;
	else cout << "NO" << endl;
}