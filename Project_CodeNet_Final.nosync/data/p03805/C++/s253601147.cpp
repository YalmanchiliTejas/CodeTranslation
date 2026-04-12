#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    rep(i,n) v[i]=i+1;
    vector<vector<int>> l(n+1);
    int a,b;
    rep(i,m){
        cin >> a >> b;
        l[a].push_back(b);
        l[b].push_back(a);
    }

    int sum=0;
    bool ans;
    do{
        if(v[0]!=1) break;
        int p=1;
        rep2(i,1,n){
            ans=false;
            rep(j,l[p].size()){
                if(v[i]==l[p][j]){
                    ans=true;
                    p=v[i];
                    break;
                }
            }
            if(!ans) break;
        }
        if(ans) sum++;
    }while(next_permutation(v.begin(),v.end()));

    cout << sum << endl;

    return 0;
}