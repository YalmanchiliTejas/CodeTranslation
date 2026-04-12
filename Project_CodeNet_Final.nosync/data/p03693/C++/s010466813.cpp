#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


int main(){
    int N, M, A, B, C;
    string s1, s2;
    cin >> A >> B >> C;
    int n = A * 100 + B * 10 + C;
    if(n % 4==0)cout <<"YES" << endl;
    else cout <<"NO" << endl;
}