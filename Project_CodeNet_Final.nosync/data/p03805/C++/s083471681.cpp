#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int G[9][9];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        G[a][b]=1;
        G[b][a]=1;
    }
    vec A;
    rep(i,n-1) A.push_back(i+2);
    int ans=0;
    do{
        int z=1;
        rep(i,n-1){
            if(i==0){
                if(!G[1][A[i]]) z=0;
            }
            else if(!G[A[i-1]][A[i]]) z=0;
        }
        if(z) ans++;
    }while(next_permutation(all(A)));
    cout<<ans;
}