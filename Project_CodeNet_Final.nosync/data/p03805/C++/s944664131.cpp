#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;cin >> n >> m;
    vector<vector<bool>> c(n,vector<bool>(n));
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        a--,b--;
        c[a][b]=true;
        c[b][a]=true;
    }
    vector<int> p(n);
    for(int i=0;i<n;i++){
        p[i]=i;
    }
    int ans=0;
    do{
        bool f=true;
        if(p[0]!=0){
            break;
        }
        for(int i=0;i<n-1;i++){
            if(!c[p[i]][p[i+1]]){
                f=false;
            }
        }
        if(f){
            ans++;
        }
    }while(next_permutation(p.begin(),p.end()));
    cout << ans << endl;
}