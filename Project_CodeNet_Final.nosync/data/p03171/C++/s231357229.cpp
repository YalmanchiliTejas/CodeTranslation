#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define sa(a,n) for(int i =0 ; i<n ; i++) cin>>a[i]
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define pb push_back
#define inf 2e18
#define scan() int n; cin>>n ; int a[n]; for(int i = 0 ; i<n ; i++) cin>>a[i]
#define print(a,n) for(int i = 0 ; i < n ; i++) cout<<a[i]<<' '
#define mem(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
#define N 3005
int n;
int a[30005];
int catche[N][N];
int dp(int l , int h){
    if(l>h)return -inf;
    if(l==h) return a[l];
    if(h-l==1){
        return max(a[l],a[h]);
    }
    int &ans=catche[l][h];
    if(ans!=-1) return ans;
    ans=0;
    ans=a[l]+min(dp(l+1,h-1),dp(l+2,h));
    ans=max(ans,a[h]+min(dp(l+1,h-1),dp(l,h-2)));
    return ans;
}

int32_t main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        mem(catche,-1);
        cin >> n;
        int i;
        int s=0;
        for(i=1; i<=n; i++){ cin >> a[i]; s+=a[i];}
        int x=dp(1,n);
        int y=s-x;
        cout << x-y << '\n';



        
        

}