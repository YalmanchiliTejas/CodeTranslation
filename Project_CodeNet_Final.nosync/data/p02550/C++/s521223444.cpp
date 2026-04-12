#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 1000000;
ll mod = INF;


int main(){
    ll n,x,m;
    vector<ll> circle;
    ll ans=0;
    ll start=0;
    bool used[maxn+1];

    cin >> n>>x>>m;
    ll cpx=x;
    for(int i=1;i<=100000;i++){
        //cout << x<<" ";
        if(!used[x]){
            circle.push_back(x);
            used[x]=true;
        }else{
            start=x;
            break;
        }
        x=x*x%m;
    }
    //cout << endl;

    bool flag=false;
    ll headsize=0;
    ll headsum=0;
    ll circlesize=0;
    ll circlesum=0;
    rep(i,circle.size()){
        
        if(circle[i]==x)flag=true;
        if(flag){
            circlesize++;
            circlesum+=circle[i];
        }else{
            headsize++;
            headsum+=circle[i];
        }
    }
    // cout << endl;

    // cout << "circle size,sum= "<<circlesize<<" "<<circlesum<<endl;
    // cout << "head size,sum= "<<headsize<<" "<<headsum<<endl;

    if(headsize>=n){
        x=cpx;
        rep(i,n){
            ans+=x;
            x=x*x%m;
        }
    }else{
        //cout << "check"<<endl;
        ans+=headsum;
        n-=headsize;
        ans+=circlesum*(n/circlesize);
        //cout <<"Yes"<<endl;
        ll rest=n%circlesize;
        x=start;
        rep(i,rest){
            ans+=x;
            x=x*x%m;
        }
    }

    cout << ans<<endl;

    return 0;
}