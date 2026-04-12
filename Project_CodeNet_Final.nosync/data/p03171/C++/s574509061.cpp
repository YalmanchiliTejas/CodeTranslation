#include<bits/stdc++.h>

#define range 524289
#define mod 1000000007
#define eps 1e-9
#define PI 3.14159265358979323846
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define ALL(V) V.begin(), V.end()
#define _ <<" "<<

using namespace std;

typedef  long long int ll;
typedef vector <ll> vi;
typedef vector<vi> vvi;
typedef pair <ll, ll> ii;
typedef pair<int, pair<int,int> > iii;
typedef vector<ii> vii;
typedef vector<iii> viii;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t = 1;
	// cin>>t;
	while(t--){

        int n, k;
        cin>>n;
        vi a(n);
        ll sum = 0;
        for (int i = 0; i < n; ++i)
        {
            /* code */
            cin>>a[i];
            sum += a[i];
        }
        vvi dp(n, vi(n));
        k = 0;


        for(int l=n-1; l>=0; l--){
            for(int r=l; r<n; r++){
                dp[l][r] = max(a[l]-(l+1<=r ? dp[l+1][r]:0), a[r]-(r-1>=l?dp[l][r-1]:0));
            }
        }
        cout<<dp[0][n-1];




	}

    return 0;
}
