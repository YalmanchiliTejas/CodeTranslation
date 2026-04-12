#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    int n,m;
    cin>>n>>m;
    bool mat[n][n]={};
    rep(i,m){
        int t,s;
        cin>>t>>s;
        t--;s--;
        mat[t][s]=mat[s][t]=true;
    }
    vector<int> v(n-1,0);
    rep(i,n-1){
        v[i]=i+1;
    }
    DEBUG{
        rep(i,n-1){cout << v[i] << " ";}
        cout << endl;
    }
    int res=0;
    do {
        bool flg=true;
        int now=0;
        for(auto x:v){
            DEBUG{
                cout << "x: " << x << " now: " << now<<endl;
            }
            if(!mat[now][x]){
                flg=false;
                break;
            }
            now=x;
        }
        if(flg){res++;}
    }while(next_permutation(v.begin(), v.end()));
    cout << res << endl;
    return 0;
}
