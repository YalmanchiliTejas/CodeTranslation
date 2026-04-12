#include <iostream>
#include <vector>

#define ll long long
using namespace std;

vector<ll> layer;
vector<ll> pati;

ll eat_pati(int n, ll x){

    if(n == 1){
        if(x == 5) return 3;
        if(x == 0) return 0;
        return x - 1;
    }

    if(layer[n - 1] + 1 >= x){
        return eat_pati(n - 1, x - 1);
    }else if(layer[n - 1] + 2 == x){
        return eat_pati(n - 1, x - 2) + 1;
    }else if(layer[n - 1] * 2 + 2 >= x){
        return pati[n - 1] + 1 + eat_pati(n - 1, x - 2 - layer[n - 1]);
    }else return pati[n - 1] * 2 + 1;
}

int main(){
    
    int n;
    ll x;
    cin >> n >> x;

    layer.push_back(1);
    pati.push_back(1);

    for(int i = 1; i <= n; i++){
        layer.push_back(layer[i - 1] * 2 + 3);
        pati.push_back(pati[i - 1] * 2 + 1);
    }

    cout << eat_pati(n, x) << endl;

    return 0;
}