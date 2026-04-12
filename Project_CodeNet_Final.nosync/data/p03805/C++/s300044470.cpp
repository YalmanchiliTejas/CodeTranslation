#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const int N = 3e5+6;
const int mod = 1e9+7;
const int inf = 1e8;
int g[22][22];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x][y] = g[y][x] = 1;
    }
    int ans = 0;
    int a[12];
    for(int i=0;i<n;i++)a[i] = i+1;
    do{
        if(a[0]!=1)break;
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(g[a[i]][a[i-1]]==0)cnt = 0;
        }
        ans+=cnt;
    }while(next_permutation(a,a+n));
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
