#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
#define rep(i,n) for(ll i=0;i<(n);i++)

using namespace std;


 
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)   cin >> a[i];

    list<ll> res;
    if(n%2 == 0){
        rep(i, n/2){
            res.push_back(a[2*i]);
            res.push_front(a[2*i+1]);
        }
    }
    else{
        rep(i, n/2){
            res.push_front(a[2*i]);
            res.push_back(a[2*i+1]);
        }
        res.push_front(a[n-1]);
    }


    string pt = "";
    for(auto iter = res.begin(); iter != res.end(); iter++){
        cout << pt << *iter;
        pt = " ";
    }

    cout << endl;

 
    return 0;
}