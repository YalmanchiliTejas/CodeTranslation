#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
//-std=c++11
#define print(x) printf("%.12f",x);
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i, n) for(int i =0 ; i < n; ++i)
#define repr(i, n) for(int i=n-1;i>=0;i--)
#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define Repr(i,a,b) for(int i=a;i>=b;i--)
#define pii pair < int, int >
#define iter ::iterator
#define forit(a) for(it=a.begin();it!=a.end();it++)
typedef vector<int> vi;
typedef  long long ll;
const int inf = int(1e9);
const int mod = inf + 7;
const int N = (int)2e5 + 5;

void solve(){
		int n;
		cin>>n;
		int a[n];
		int mx=-1e8,cnt=0;
		rep(i,n){
			cin>>a[i];
			cnt+=(a[i]>=mx);
			mx=max(mx,a[i]);	
		}
		cout<<cnt<<endl;
 
}


int main(){
	Red;
	int t=1;
	//cin>>t;
	while(t--)
	solve();
	return 0;
}