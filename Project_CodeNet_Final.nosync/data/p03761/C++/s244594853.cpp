#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    int N; cin>>N;
    string S[N];
    rep(i, N){
        cin>>S[i];
    }

    map<char, long> m;

    int i=0;
    for(string s : S){
        map<char, long> a;
        for(char c : s){
            a[c]++;
        }
        if(i == 0){
            for(auto v : a){
                m[v.first] = v.second;
            }
        }else{
            for(auto v : m){
                m[v.first] = min(v.second, a[v.first]);
            }
        }
        i++;
    }

    for(auto v : m){
        rep(i, v.second) cout<<v.first;
    }
    cout<<endl;
}
