#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main(){
    ll N,ans = 0;
    cin >> N;
    vector<ll> X(N),Y(N);

    for(ll i = 0;i < N;i++){
        cin >> X.at(i);
        Y.at(i) = X.at(i);
    }

    sort(Y.begin(),Y.end());

    for(ll i = 0;i < N;i++){
        if(X.at(i) == Y.at(N/2-1)){
            cout << Y.at(N/2) << endl;
        }else if(X.at(i) == Y.at(N/2))
            cout << Y.at(N/2-1) << endl;
        else if(X.at(i) < Y.at(N/2-1))
            cout << Y.at(N/2) << endl;
        else if(X.at(i) > Y.at(N/2))
            cout << Y.at(N/2-1) << endl; 
    }

}