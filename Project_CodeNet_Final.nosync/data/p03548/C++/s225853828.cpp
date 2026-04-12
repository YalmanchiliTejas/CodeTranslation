#include <bits/stdc++.h>
using namespace std;
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
#define MOD        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define N	 100
void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<(a-c)/(b+c)<<endl;
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

