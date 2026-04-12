#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int INF_INT = 1e9;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<class TYPE>
struct edge{
    TYPE to,cost; 
    edge(TYPE t,TYPE c){
        to = t;
        cost = c;
    }
};

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    ll sum = 0;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll res = 0;
    for(int i = 0; i < N - 1; i++){
        sum -= a[i];
        res = (res + ((a[i] % MOD) * (sum % MOD)) % MOD) % MOD;
    }
    cout << res << endl;
    return 0;
}
