#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2

using namespace std;

int MOD = 1000000007;

signed main(){
    int n;
    cin >> n;

    if(n == 3 || n == 5 || n == 7){
        cout << "YES" <<endl;
    }else{
        cout << "NO"<<endl;
    }

    return 0;
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl 