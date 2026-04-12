#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

ll rec(int n, ll x){
    if(n == 0) return 1;
    ll len = (1LL<<(n+1)) - 3;//n-1の長さ
    ll niku = (1LL<<n) - 1;
    if(x == 1)return 0;
    else if(x <= len+1) return rec(n-1, x-1);
    else if(x == len+2) return niku+1;
    else if(x <= (len+1)*2) return niku+1+rec(n-1, x-len-2);
    else return niku*2+1;
}

int main(){
    int n;
    ll x; 
    cin >> n >> x;
    cout << rec(n, x) << endl;
}