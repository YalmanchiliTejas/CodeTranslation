#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define all(v) (v).begin(),(v).end()
#define UNIQUE(v) (v).erase( unique( all(v) ), (v).end() );
#define MOD 1000000007

int main(){
	int x;	cin >> x;

	if( x >= 30 )	cout << "Yes" << endl;
	else	 		cout << "No" << endl;

	return 0;
}
