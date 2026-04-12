#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<long long>;


void solve(long long n, std::vector<std::string> S){
    vector<vll> record(n, vll(26, 0));
    for(ll i=0; i< n; i++){
        for(ll j=0; j < S[i].length(); j++){
            record[i][S[i].at(j)-'a']++;
        }
    }
    vll ans(26, 10000);
    for(ll j=0; j<26; j++){
        for(ll i=0; i< n; i++){
            ans[j] = min(ans[j], record[i][j]);
        }
    }
    for(ll j=0; j< 26; j++){
        if (ans[j]>0){
            for(ll k=0; k< ans[j]; k++){
                cout<<(char)(j+'a') ;
            }
        }
    }
    cout << endl;

}

int main(){
    long long n;
    scanf("%lld",&n);
    std::vector<std::string> S(n);
    for(int i = 0 ; i < n ; i++){
        std::cin >> S[i];
    }
    solve(n, std::move(S));
    return 0;
}
