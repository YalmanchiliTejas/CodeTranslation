#include <bits/stdc++.h>
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

#define ll long long

#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define alll(it,A) for(it=A.begin();it!=A.end();it++)

#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl

#define mp make_pair
#define pb push_back
#define all(A)  A.begin(),A.end()
#define ft first
#define sd second

#define pll pair<ll,ll>
#define pii pair<int,int>
#define V vector<ll>
#define VP vector<pll>
#define SP set<pll>
#define VB vector<bool>
#define S set<ll>
#define MS multiset<ll>
#define VV vector<V>
#define VS vector<S>
#define PQi priority_queue< int >
#define PDQi priority_queue< int ,vector< int > ,greater< int > >
#define PQl priority_queue< ll >
#define PDQl priority_queue< ll ,V,greater< ll > >
//#define inf 1e5
#define mod 1000000007
bool isprime(ll n){
    ll i;
    if(n==2||n==3)return 1;
    ll flag=0;
    for(i=2;i<=sqrt(n)+1;i++){
        if(n%i==0){
            flag=1;
            break;
        }
    }
    if(flag)return 0;
    else return 1;
}
//ll cost[200001];
//V adj[200001];
//ll d[200001]={0};
//ll dam[200001]={0};
//V rdj[200001];
//ll visited[200001]={0};
//ll par[200001]={0},rnk[200001]={0};
//ll find(ll a){
//	if(par[a]==a)return par[a];
//	return find(par[a]);
//}
//void unionf(ll a,ll b){
//	a=find(a);
//	b=find(b);
//	//if(a==b)continue;
//	if(rnk[a]>rnk[b]){
//		par[b]=a;
//		rnk[a]+=rnk[b];
//	}
//	else{
//		par[a]=b;
//		rnk[b]+=rnk[a];
//	}
//}
ll kadane(ll a[],ll n){
    ll sumtill=0,maxtill=0,start=0,ending=0,start1=0;
    rep(i,0,n){
        sumtill+=a[i];
       // err1(sumtill);
        if(sumtill>maxtill){
            maxtill=sumtill;
            start=start1;
            ending=i;
        }
        if(sumtill<0){
            start1=i+1;
            sumtill=0;
        }
    }
    return maxtill;
}
ll pow1(ll a,ll b,ll mod1){
    int res=1;
    if(b<0) b+=mod1-1;
    while(b>0){
        if(b&1){
        	res=(res*a)%mod1;
		}
        a=(a*a)%mod1;
        b>>=1;
    }
    return res%mod1;
}
int main(){
	fast
    ll t;
    //cin>>t;
    t=1;
    while(t--){
            ll n;
            cin>>n;
            ll a[n+1];
            rep(i,1,n+1)cin>>a[i];
            ll dp[n+1][n+1];
            rep(i,0,n+1){
                rep(j,0,n+1){
                    if(i==j)dp[i][j]=a[i];
                    else dp[i][j]=0;
                }
            }
            repb(i,n-1,1){
                rep(j,i+1,n+1){
//                    if(a[i]>a[j]){
//                        dp[i][j]=a[i]-dp[i+1][j];
//                    }
//                    else if(a[i]<a[j]){
//                        dp[i][j]=a[j]-dp[i][j-1];
//                    }
//                    else dp[i][j]=a[i]-min(dp[i][j-1],dp[i+1][j]);
                    dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
                    //err3(i,j,dp[i][j]);
                }
            }
            cout<<dp[1][n];
    }
    return 0;
}

