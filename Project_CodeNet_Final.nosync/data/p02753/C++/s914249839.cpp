#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <iomanip>
#include <map>

#define REP(i, n ,N) for(ll i = (n); i < (N); i++)
//#define RREP(i, n ,N) for(ll i = (N-1); i >= (n); i--)
#define p(s) cout<<(s)<<endl
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl

using namespace std;
typedef long long  ll;

const long long MOD = 1e9+7;

int main(){

    string s;
    cin >> s;

    if(s == "BBB" or s == "AAA"){
        p("No");
    } else {
        p("Yes");
    }

    return 0;
}