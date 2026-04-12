#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N;cin >> N;
vector<vector<ll>> A(N, vector<ll>(26, 0));
vector<ll> Ans(26);

rep(i, 0, N){

string S;cin >> S;

    rep(j, 0, S.size()){

    ll I = S[j] - 2*'0' - 1;A[i][I]++;

    }

}

Ans = A[0];

rep(i, 1, N){

    rep(j, 0, 26)Ans[j] = min(Ans[j], A[i][j]);

}

vector<char> ANS;

rep(i, 0, 26){
char c = i + 2*'0' + 1;
    rep(j, 0, Ans[i]){
    ANS.push_back(c);
    }
}

sort(ALL(ANS));

for(auto a : ANS)cout << a;
}
