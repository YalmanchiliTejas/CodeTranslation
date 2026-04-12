#include <bits/stdc++.h>
#include <stdio.h>
#include <cmath>
using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)

typedef long long ll;

const ll inf = 1e18+7;
const ll mod = 1e9+7;


int main() {

    int n;
    cin>>n;

    vector<int>cnt(26),cntzero(26),cntmin(26,51);

    rep(i,n){
        string s;
        cin>>s;

        rep(i,s.size()){
            cnt[s[i]-'a']++;
        }

        rep(i,26){
            if(cnt[i]<cntmin[i]){
                cntmin[i]=cnt[i];
            }
        }

        cnt=cntzero;
    }

    string ans;

    rep(i,26){
            rep(j,cntmin[i]){
                ans.push_back(i+'a');
        }
    }

    cout<<ans<<endl;

    /*
    rep(i,26){
        cout<<cntmin[i]<<endl;
    }
    */
}
