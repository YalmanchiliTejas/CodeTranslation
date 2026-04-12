#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<cmath>
#include<cstdio>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P = pair<int,int>;

int main(){
    int n,ans=1;
    cin >> n;
    vector<int> mou(n);
    rep(i,n) cin >> mou[i];
    for(int i=1; i<n; i++){
        bool ansc = true;
        rep(j,i){
            if(mou[j] > mou[i] && i != j)
                ansc = false;
        }
        if(ansc)
            ans++;
    }

    cout << ans << endl;
    return 0;
}

