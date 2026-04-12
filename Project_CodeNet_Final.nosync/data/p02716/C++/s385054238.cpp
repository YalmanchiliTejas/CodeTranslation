#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)
#define ll long long
int in() {int x; cin>>x; return x;}
ll lin() {ll x; cin>>x; return x;}
string sin() {string x;cin>>x;return x;}
using graph = vector<vector<int>>;
using graph2 = vector<vector<pair<int, int>>>;

bool ifprime(int x){
    if(x==1)return false;
    if(x==2)return true;
    if(x%2==0)return false;
    for(int i=2;i*i<=x;i++){if(x%i==0)return false;}
    return true;
}
ll mod(ll x, ll y){if(x>=0||x%y==0) return x%y;return y+x%y;} //mod including minus
ll dv0(ll x, ll y){if(x>=0||x%y==0)return x/y;return x/y-1;} //rnd down
ll dv1(ll x, ll y){if(x%y==0) return dv0(x,y);return dv0(x,y)+1;} //rnd up

//Start from Here
int main(){
    int N;
    cin>>N;
    ll a[(N+1)/2][3];
    ll c[N];
    rep(i, N){
        cin>>c[i];
    }
    if(N%2==1){
        a[0][0]=0;
        a[0][1]=0;
        a[0][2]=c[0];
        rep2(i, (N-1)/2){
            a[i][1]=max(a[i-1][0],a[i-1][1])+c[2*i];
            a[i][0]=max(c[2*i-1]+a[i-1][0],a[i-1][2]);
            a[i][2]=a[i-1][2]+c[2*i];
        }
        cout<<max(a[(N-1)/2][0],a[(N-1)/2][1])<<endl;
    }else{
        a[0][0]=0;
        a[0][1]=c[0];
        rep2(i, N/2-1){
            a[i][0]=max(a[i-1][0]+c[2*i-1],a[i-1][1]);
            a[i][1]=a[i-1][1]+c[2*i];
        }
        cout<<max(a[N/2-1][0]+c[N-1],a[N/2-1][1])<<endl;
    }

}