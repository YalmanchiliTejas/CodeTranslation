#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
#define inf 1000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define f first
#define ss second
#define pb push_back

int n, m, ans=0;
vi  adj[1010], v;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin >> n;
cin >> m;
int x, y;
rep(i, 1, m){
cin >> x >> y;
adj[x].pb(y);
adj[y].pb(x);
}

rep(i,1,n){
v.pb(i);
}

do{
    bool flag = true;
    if(v[0]!=1)continue;
    rep(i, 0, n-2){
    int a = v[i+1];
    bool f1=false;
    for(auto t: adj[v[i]]){
        if(t==a)f1=true;;
    }
    if(f1)continue;
    else flag = false;
    }
    if(flag)ans++;
}
while(next_permutation(v.begin(), v.end()));


cout << ans << endl;

return 0;}
