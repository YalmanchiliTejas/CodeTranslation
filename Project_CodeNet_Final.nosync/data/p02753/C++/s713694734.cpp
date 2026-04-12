#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
const int inf = 1 << 30;
const ll linf = 1e18;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

string S;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S;
    cout << (S[0] != S[1] || S[1] != S[2] ? "Yes" : "No") << endl;
    return 0;
}