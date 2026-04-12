//Align

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define YN(flag) (flag?"Yes":"No")
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n,nc;cin>>n;
    deque<int>a(n),ac;
    rep(i,0,n)cin>>a[i];
    ac=a;
    sort(range(a));
    int la=0,l=a[0],r=a[0],w=a[0],q=a[0];
    a.pop_front();
    for(int i=0;a.size()>1;i++){
        if(i%2==0){
            w=a.back();a.pop_back();
            q=a.back();a.pop_back();
        }else{
            w=a.front();a.pop_front();
            q=a.front();a.pop_front();
        }
        la+=max(abs(w-l)+abs(q-r),abs(w-r)+abs(q-l));
        l=w;r=q;n-=2;
    }
    if(a.size()==1)la+=max(abs(w-a[0]),abs(q-a[0]));

    a=ac;
    sort(range(a),greater<int>());
    int ans=la;
    la=0;l=a[0];r=a[0];w=a[0];q=a[0];
    a.pop_front();
    for(int i=0;a.size()>1;i++){
        if(i%2==0){
            w=a.back();a.pop_back();
            q=a.back();a.pop_back();
        }else{
            w=a.front();a.pop_front();
            q=a.front();a.pop_front();
        }
        la+=max(abs(w-l)+abs(q-r),abs(w-r)+abs(q-l));
        l=w;r=q;
    }
    if(a.size()==1)la+=max(abs(w-a[0]),abs(q-a[0]));

    cout<<max(ans,la)<<nnn;
    return 0;
}