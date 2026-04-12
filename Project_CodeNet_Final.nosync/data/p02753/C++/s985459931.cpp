#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1e9 + 7;
typedef pair<int,int> P;// pair型は２つの値の組を表せる

int main(){
    string S; cin >> S;
    if (S[0]==S[1] && S[1]==S[2]) cout << "No";
    else cout << "Yes";
}