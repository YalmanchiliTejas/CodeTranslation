#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ((int)(x).size())
#define in(x) int x;cin>>x
#define inn(x, y) int x,y;cin>>x>>y
#define innn(x, y, z) int x,y,z;cin>>x>>y>>z
#define bit(n) (1<<(n))

#define out(x) cout<<(x)<<endl;
#define outt(x,y) cout<<(x)<<" "<<(y)<<endl;
#define err(x) cerr<<(x)<<endl;
#define errr(x,y) cerr<<(x)<<" "<<(y)<<endl;
#define errrr(x,y,z) cerr<<(x)<<" "<<(y)<<" "<<(z)<<endl;

#define rep(i,n) for (int i=0;i<(n);i++)
#define repp(i,n) for (int i=1;i<=(n);i++)
#define reppp(j, i, n) for (int j=i+1; j<n; j++)

#define lim5 100002
#define lim9 1000000002

#define deg(rad) (((rad)/2/M_PI)*360)
#define mid(min, max) ((min + max) / 2)

int main() {
	string s;
	cin >> s;

	if (abs(s[0] - s[1]) || abs(s[1] - s[2])) {
		out("Yes");
		return 0;
	}

	out("No");

	return 0;
}
