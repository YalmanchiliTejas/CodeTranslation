#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<ll, ll>P;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void SAY(bool YES){cout<<(YES?"YES":"NO")<<endl;};
void Say(bool Yes){cout<<(Yes?"Yes":"No")<<endl;};

const ll MOD = 1000000007;

int main(){

    ll N;
    cin >> N;
    vector<ll>cnt(256, 999);
    for(ll i = 0; i < N; i++){
        vector<ll>tmp(256, 0);
        string s;
        cin >> s;
        for(ll j = 0; j < s.size(); j++)tmp[s[j]]++;
        for(ll j = 0; j < 256; j++)chmin(cnt[j], tmp[j]);
    }
    for(char c = 'a'; c <= 'z'; c++){
        for(ll i = 0; i < cnt[c]; i++)cout << c;
    }
    cout << endl;

    return 0;
}