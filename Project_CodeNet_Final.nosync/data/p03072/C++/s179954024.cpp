#include <bits/stdc++.h>

#define ipair pair<int,int>
#define rep(i,n) for(i=0;i<n;i++)
#define repj(i,j,n) for(i=j;i<n;i++)

#define PB(a,i) (a).push_back(i)
#define ALL(a) (a).begin(),(a).end()

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
	vi h;
	int n, i, j, k;

	cin >> n;
	h.resize(n);

	rep(i, n) {
		cin >> h[i];
	}

	k = 1;
	j = h[0];
	
	repj(i, 1, n) {
		if (j <= h[i]) {
			k++;
			j = h[i];
		}
	}

	cout << k << endl;

	return 0;
}
