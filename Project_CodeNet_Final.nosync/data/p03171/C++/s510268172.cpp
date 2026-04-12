#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector<long long int> vl;
#define pb push_back
#define mp make_pair

ll dpx[3001][3001];
ll dpy[3001][3001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int n;
	cin >> n;

	vi a(n+1, 0);
	for(int i=0;i<n;i++) cin >> a[i];

	
	for(int j = 0;j<n;j++){
		dpx[j][j] = a[j];
		dpy[j][j] = -a[j];
		for(int i=j-1;i>=0;i--){
			dpx[i][j] = max(a[i]+dpy[i+1][j], dpy[i][j-1]+a[j]);
			dpy[i][j] = min(dpx[i+1][j]-a[i], dpx[i][j-1]-a[j]);
		}
	}
	
	cout << dpx[0][n-1] << endl;
	return 0;
}

