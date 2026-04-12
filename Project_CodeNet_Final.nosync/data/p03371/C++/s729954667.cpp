#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) (x).begin(),(x).end()
#define F(i,x,n,y) for(i=x;i<n;i+=y)
#define fi(i,x,n) for(i=x;i<n;++i)
#define f(n) for(int i=0;i<n;++i)
#define fr(i,x,n) for(i=x;i>=n;--i)
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll ans=a*x+b*y;
    int i;
    F(i,2,2*(max(x,y))+1,2){
        ll res=i*c;
        if(x-(i>>1)>=0){
            res+=(x-(i>>1))*a;
        }
        if(y-(i>>1)>=0){
            res+=(y-(i>>1))*b;
        }
        ans=min(ans,res);
    }
    
    cout<<ans<<endl;
    return 0;
}

