#include<bits/stdc++.h>
using namespace std;
#define SORT(x) sort(x.begin(),x.end())
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
    ll a,b,c,x,y,ans=0;
    cin>>a>>b>>c>>x>>y;
    ll m=(a+b>c*2)?c*2:a+b;
    //メインのピザを集める手段
    while(x>0&&y>0){
        x--;y--;
        ans+=m;
    }
    if(x==0&&y==0){
        cout<<ans<<endl;return 0;
    }
    ll rem=max(x,y),d=(x!=0)?a:b;
    if(c*2>d){
        //残りの一個の方は単品買いがいい
        while(rem!=0){
            rem--;ans+=d;
        }
        cout<<ans<<endl;return 0;
    }
    else{
        //残りの一個集めるのにもダブルの買うのがいい
        while(rem!=0){
            rem--;ans+=2*c;
        }
        cout<<ans<<endl;return 0;
    }
    return 0;
}
