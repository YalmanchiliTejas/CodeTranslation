#include <bits/stdc++.h>
#define CYES cout<<"Yes"<<"\n";
#define CNO cout<<"No"<<"\n";
#define CFS cin.tie(nullptr);ios::sync_with_stdio(false);
#define CST(x) cout<<fixed<<setprecision(x);
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using MaxHeap = priority_queue<T>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
const int IINF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = (int) 1e9 + 7;
const string MM = " ";

int main(){
    int n, m;
    cin >> n >> m;
    if (n == m) {
        CYES;
    }
    else {
        CNO;
    }
}