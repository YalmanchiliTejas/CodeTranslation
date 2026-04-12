#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <map>
#include <cmath>
#include <limits>
#define ll long long int
#define rep(i,n) for(int i = 0;i < n;i++)
#define pb push_back
#define mp make_pair

using namespace std;

vector<ll> a;
vector<ll> paty;

ll r(ll n1,ll x1){

    if(n1 == 0){
        if(x1 <= 0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if(x1 <= a[n1 - 1] + 1){
        return r(n1 - 1,x1 - 1);
    }
    else{
        return paty[n1-1] + 1 + r(n1 - 1,x1 - 2 - a[n1 - 1]);
    }
}

int main(){

    ll n, x;
    cin >> n >> x;

    a.resize(n);
    paty.resize(n);

    paty[0] = 1;
    a[0] = 1;
    for(int i = 1;i < n;i++){
        a[i] = 2 * a[i-1] + 3;
        paty[i] = 2 * paty[i-1] + 1;
    } 

    /*rep(i,n){
        cout << a[i] <<" " << paty[i] << endl;
    }*/

    cout << r(n,x) << endl;;
    
    return 0;
}