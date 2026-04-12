#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main(){
    int n,m;
    cin >> n >>m;
    vector<vector<int>> to(n,vector<int>(n));
    rep(i,n) rep(j,n) to[i][j]=0;
    
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        to[a][b]=1;
        to[b][a]=1;
    }
    
    vector<int> perm;
    rep(i,n-1){
        perm.push_back(i+1);
    }
    int res = 0;
    do{
        int temp = 0;
        bool flag = true;
        rep(i,perm.size()){
            if(to[temp][perm[i]]!=1){
                flag=false;
                continue;
            }
            temp = perm[i];
        }

        if(flag){
            res++;
        }

    }while(next_permutation(perm.begin(),perm.end()));

    cout << res << endl;

}