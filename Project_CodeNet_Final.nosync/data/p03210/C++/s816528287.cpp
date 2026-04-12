#include <iostream>
#include "bits/stdc++.h"
using namespace std;
#define print(x) cout<<x<<endl;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,a) for(ll i=0;i<a;i++)
#define jkl ll debug = 0;
#define RREP(i,a) for(ll i=a-1;i>=0;i--)
#define rrep(i,a,b) for(ll i=a-1;i>=b;i--)
#define printall(n,array) {for(ll i=0;i<n;i++){cout<<array[i]<<" ";}cout<<endl;}
#define U() cout<<endl;
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> Pi;
typedef pair<ll, Pi> V;
typedef vector<ll> VE;
const ll mod = 1e9 + 7; //10^9+7

int main(){
    int b;
    cin >> b;
    if(b == 3 || b == 5 || b == 7){
        print("YES");
    }else{
        print("NO");
    }
}