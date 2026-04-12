#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORD(i,a,b) for(int i=(a);i>(b);i--)
typedef long long ll;
const ll mod =1e9 +7;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    ll sum=0;
    FOR(i,0,n){
        cin>>arr[i];
        sum=(sum+arr[i])%mod;
    }
    
    ll to=0;
    ll d=0;

    ll ans=0;
    FOR(i,0,n){
        d=(d+arr[i])%mod;
       to=(sum-d)%mod;
        if(to<0) to=(to+mod)%mod;
        ans=(ans+(arr[i]%mod*to%mod)%mod)%mod;
    }
    cout<<ans<<endl;


    return 0;
}
