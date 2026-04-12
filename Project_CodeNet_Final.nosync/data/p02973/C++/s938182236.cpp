#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

const int maxv = 100005;

vector<int> d;

bool isOK(ll mid, ll key){
    if (key > d[mid]) return true;
    else return false; 
}

ll binary_search(ll key){
    ll ng = -1;
    ll ok = d.size();

    while(abs(ok-ng)>1){
        int mid = (ok+ng) / 2;

        if(isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    rep(i,N){
        ll a = A[i];
        ll index = binary_search(a);
        if (index != d.size()){
            d[index] = a;
        }else{
            d.push_back(a);
        }
    }

    cout << d.size() << endl;
}