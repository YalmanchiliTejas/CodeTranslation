                            #include <bits/stdc++.h>

                            typedef long long ll;
                            typedef double ld;
                            #define rep(i,a,n) for(ll i=(a); i<(n); i++)
                            #define per(i,a,n) for(ll i=(n-1); i>=(a); i--)
                            #define F first
                            #define S second
                            #define maxx(a,b) a=max(a,b)
                            #define minn(a,b) a=min(a,b)
                            #define db(x) cerr<<#x<<" = "<<x<<endl
                            #define N 1111111
                            #define mod 1000000007
                            #define rt return
                            #define inf 1000000000

                            using namespace std;

                            ll dp[3456][3456],a[3456];

                            ll getmax(ll l, ll r)
                            {
                                if(l==r)rt dp[l][r]=a[l]-a[l-1];
                                if(dp[l][r])rt dp[l][r];
                                rt dp[l][r]=max(a[r]-a[l-1]-getmax(l+1,r),a[r]-a[l-1]-getmax(l,r-1));
                            }

                            int main(){

                                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

                                //freopen("Ulug'bek","r",stdin);
                                //freopen("Abdimanabov","w",stdout);

                               int n; cin>>n;
                               ll s=0;
                               rep(i,1,n+1)cin>>a[i],a[i]+=a[i-1];

                               cout<<getmax(1,n)-(a[n]-getmax(1,n));

                            rt 0;
                            }

















