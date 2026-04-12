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
#define No cout<<"No"<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
    int n;
    cin>>n;
    ll a[n];
    rep(i,n){
        cin>>a[i];
    }
    vector<ll> b;
   
    for(int i=n-1;i>=0;i-=2){
        b.push_back(a[i]);
        }
    for(int i=(n%2==0?0:1);i<n;i+=2){
        b.push_back(a[i]);
    }
    rep(i,n-1){
        cout<<b[i]<<' ';
    }
    cout<<b[n-1]<<endl;
    return 0;
}
