#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int r,g,b; cin>>r>>g>>b;
	cout << ((100*r+10*g+b)%4==0 ? "YES" : "NO") << endl;
	return 0;
}
