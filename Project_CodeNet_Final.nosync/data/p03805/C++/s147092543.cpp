#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n,m;
    cin>>n>>m;
    
    vv road(n, vi (n,0));
    
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        road[a][b] = 1;
        road[b][a] = 1;
    }
    
    vi p(n);
    rep(i,n)p[i]=i;
    
    int ans = 0;
    
    do{
        bool ok = true;
        if(p[0]!=0)continue;
        for(int i=1; i<n; i++){
            if(road[p[i-1]][p[i]])continue;
            ok = false;
            break;
        }
        if(ok)ans++;
    } while(next_permutation(p.begin(), p.end()));
    
    cout << ans << endl;
    
    return 0;
}