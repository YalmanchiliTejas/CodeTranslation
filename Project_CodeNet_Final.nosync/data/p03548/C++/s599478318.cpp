#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int x,y,z; cin>>x>>y>>z;
	x-=z;
	cout << x/(y+z) << endl;
	return 0;
}
