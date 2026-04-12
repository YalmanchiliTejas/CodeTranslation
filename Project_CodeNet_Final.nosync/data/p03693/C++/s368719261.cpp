#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	if( (a*100 + b*10 + c) % 4 == 0 ){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}