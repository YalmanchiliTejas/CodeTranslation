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

string s;
int n;
int k;
vi a;
vector<vvi> dp;

ll solve(int i, int sum, int flag){
    if(i==n){
        return (sum==k);
    }
    if(dp[i][sum][flag]!=-1) return dp[i][sum][flag];
    int lim = 9;
    if(!flag){
        lim = a[i];
    }
    ll ans =0;
    for (int j = 0; j<=lim; ++j)
    {
        /* code */
        int sum1 = sum+j;
        int flag1 = flag;
        while(sum1>k){
            sum1 -= k;
        }
        if(flag==0&&j<lim) flag1 = 1;
        ans = (ans + solve(i+1, sum1, flag1))%mod;
    }
    // cout<<i<<" "<<sum<<" "<<flag<<" "<<ans<<endl;
    return dp[i][sum][flag] = ans;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t = 1;
	// cin>>t;
	while(t--){
        cin>>s;
        n = s.size();
        a = vi(n);
        for (int i = 0; i < n; ++i)
        {
            /* code */
            a[i] = s[i]-'0';

        }
        cin>>k;
        dp = vector<vvi>(n, vvi(k+1, vi(2, -1)));

        cout<<solve(0, 0, 0)<<endl;

	}

    return 0;
}
