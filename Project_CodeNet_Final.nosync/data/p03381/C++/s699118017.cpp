#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define FOR(i,a,b) for(i=a;i<=b;i++)

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

ll N;
ll X[200010],x[200010];


int main()
{
	cin >> N;
	for(ll i=1;i<=N;i++){
		cin >> X[i];
		x[i] = X[i];
	}
	sort(x, x+(N+1));

	for (ll i = 1; i <= N; i++) {
		if (X[i]<=x[N / 2]) {
			cout << x[N / 2 + 1] << endl;
		}
		else cout << x[N / 2] << endl;
	}

	
    return 0;
}