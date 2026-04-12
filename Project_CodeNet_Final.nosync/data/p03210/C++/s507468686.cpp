#include "bits/stdc++.h"
#define ed cout<<"\n";
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define All(obj) (obj).begin(),(obj).end()

using namespace std;


int main() {
	speed;
	int d;
	cin >> d;
	if (d == 3 || d == 5 || d == 7)cout << "YES";
	else { cout << "NO"; }
	ed;
	return 0;
}
