#include <iostream>
using namespace std;
typedef long long ll;

ll rec(ll idx, ll size){
    if(size == 1) return 1;
    if(idx == 0) return 0;
    ll subsize = (size-3) / 2;
    ll subnums = rec(subsize-1, subsize);
    if(idx == size/2) return subnums + 1;
    if(idx == size-1) return subnums*2 + 1;

    ll ret = 0;
    if(idx > size/2){
        ret += subnums + 1;
        idx -= size/2;
    }
    ret += rec(idx - 1, subsize);

    return ret;

}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n, x;
    cin >> n >> x;

    ll size = 1;
    for(int i = 0; i < n; ++i){
        size = size*2 + 3;
    }

    cout << rec(x-1, size) << endl;

}