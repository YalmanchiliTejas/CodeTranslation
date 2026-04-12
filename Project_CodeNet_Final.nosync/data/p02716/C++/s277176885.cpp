    #include <bits/stdc++.h>
    using namespace std;
 
    #define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define mod 1000000007
    #define qmod 998244353
    #define M 1000001
    #define endl "\n"
    #define all(a) (a).begin(),(a).end()
    #define rep(i,a,b) for(int i=a;i<b;++i)
    #define repr(i,a,b) for(int i=a;i>=b;--i)
    #define F first
    #define S second
    #define pb push_back
    #define mp make_pair
 
    typedef long long ll;
    typedef pair<int,int> pii;
    typedef vector<ll> vi;
    typedef vector<string> vs;
    typedef vector<pii> vii;
    typedef vector<vi> vvi; 
    
    int main(){
        
   /* #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);   
    #endif */
 
        fast;
        int n;
        ll ans=0;
        cin>>n;
        vi a(n);
        rep(i,0,n) cin>>a[i];
        if(!(n&1)){
            ll sum=0;
            rep(i,0,n) if(i&1) sum+=a[i];
            ans=sum;
            rep(i,0,n/2){
              sum+=a[i*2]-a[i*2+1];
              ans=max(ans,sum);
            }
        }
        else{
            vvi v(n+1,vi(3,0));
            rep(i,0,n){
                  if(i&1){
                    v[i+1][0]=v[i][0];
                    v[i+1][1]=max(v[i][0],v[i][1]+a[i]);
                    v[i+1][2]=v[i][2];
                  }
                  else{
                    v[i+1][0]=v[i][0]+a[i];
                    v[i+1][1]=v[i][1];
                    v[i+1][2]=max(v[i][1],v[i][2]+a[i]);
                  }
            }
            ans=max({v[n][0],v[n][1],v[n][2]});
        }
        cout<<ans;
        return 0;  
    }       
 
 
    //keep it simple stupid