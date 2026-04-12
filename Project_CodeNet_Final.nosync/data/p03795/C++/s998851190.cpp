#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ((int)(x).size())
#define in(x) int x;cin>>x
#define bit(n) (1<<(n))

#define rep(i,n) for (int i=0;i<(n);i++)
#define repp(i,n) for (int i=0;i<=(n);i++)

int main(){
	int a=0;
	in(n);

	a = (n - (n % 15)) / 15;
	cout << 800 * n - 200 * a << endl;
	
	return 0;
}
