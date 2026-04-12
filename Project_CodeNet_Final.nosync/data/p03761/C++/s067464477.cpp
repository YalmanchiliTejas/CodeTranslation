#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll n,m;
vector<ll> a;

int main(){
    int n;
    cin>>n;
    ll ans[26]={};
    rep(i,n){
        string s;ll c[26]={};
        cin>>s;
        if(i==0){
            for(auto x:s){
                ans[x-'a']++;
            }
        }
        for(auto x:s){
            c[x-'a']++;
        }
        for(int j=0;j<26;j++){
            ans[j]=min(c[j],ans[j]);
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<ans[i];j++)
        cout<<(char)('a'+i);
    }
    cout<<endl;
    return 0;
}