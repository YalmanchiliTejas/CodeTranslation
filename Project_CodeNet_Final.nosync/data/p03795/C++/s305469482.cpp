#include<bits/stdc++.h>
#define pb push_back
#define pp pop_back()
#define mp make_pair
#define fr first
#define sc second
#define sz size()
#define smin(x,y) ((x)=min((x),(y)))
#define smax(x,y) ((x)=max((x),(y)))
#define all(x) x.begin(),x.end()
#define CS ios_base::sync_with_stdio(false);
#define show(x) cerr << #x << " is " << x <<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi; 
int32_t main()
{
	int n; cin>>n;
	cout << 800 * n - 200 * (n/15) << endl;
	return 0;
}
