#include <bits/stdc++.h>

#define ll          long long
#define mp	    make_pair
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
#define N 	     10001
int A[N];
void solve(){
	int n;cin>>n;
	int nct = n;
	rep(i,0,n)cin>>A[i];
	rep(i,1,n)
		rep(j,0,i)
			if(A[j]>A[i]) {nct--;break;}
	cout<<nct<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
     t =1;
//     cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
