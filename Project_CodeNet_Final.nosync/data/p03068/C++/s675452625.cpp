#include <bits/stdc++.h>

#define ipair pair<int,int>
#define rep(i,n) for(i=0;i<n;i++)
#define repj(i,j,n) for(i=j;i<n;i++)

#define PB(a,i) (a).push_back(i)
#define ALL(a) (a).begin(),(a).end()
#define SIZE(a,n) (a).resize(n)

#define OK(i) cout<<"OK "<<i<<endl
#define Yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define NO cout<<"NO"<<endl

using namespace std;

typedef long long int lli;
typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > Matrix;



int main() {
	string s;
	int n, k, i;
	char t;

	cin >> n;
	cin >> s;
	cin >> k;

	t = s[k - 1];

	rep(i, n) {
		if (s[i] != t)s[i] = '*';
	}

	cout << s;

	return 0;
}
