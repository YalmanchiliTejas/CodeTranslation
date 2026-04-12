#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define td(v) v.begin(),v.end()
#define tdr(v) v.rbegin(),v.rend()
#define endl "\n"
#define Matrix vector<vector<int> >
using namespace std;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int INF = 2e18;
 
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
 
inline long long mod(long long n, long long m){
    long long ret = n%m;
    if(ret < 0) ret += m;
    return ret;
}
 
int exp(int a, int b, int m){
    int result = 1;
    while (b > 0){
        if (b & 1)
            result = mod(result*a,m);
 
        b >>= 1;
        a = mod(a*a,m);
    }
    return result;
}
 
pair<int,int> adj[5000][5000];
void solve(){
    int n; cin>>n;
    vector<int>vet(n);
    for(int &i : vet) cin>>i;
    for(int i=0;i<n;i++){
        adj[i][i]={vet[i],0};
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            int x = vet[j];
            int y = vet[j+i];
            int eu,ele;
            if(x+adj[j+1][j+i].second>y+adj[j][j+i-1].second){
                eu = x+adj[j+1][j+i].second;
                ele = adj[j+1][j+i].first;
            }
            else{
                eu = y+adj[j][j+i-1].second;
                ele = adj[j][j+i-1].first;
            }
            adj[j][j+i] = {eu,ele};
        }
    }
    cout<<adj[0][n-1].first-adj[0][n-1].second<<endl;
}
main(){
    fastio;
    solve();
}