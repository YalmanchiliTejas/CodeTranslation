#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	double r1,r2;cin >> r1 >> r2;
	cout << fixed << setprecision(20) << r1*r2/(r1+r2) << endl;
}