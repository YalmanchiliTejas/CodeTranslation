#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define DEBUG 1
#define ll         long long
#define REP(i, n) for (long long i = 0; i < (n); i++) 
static const ll INF = 1000000000000000000LL;
static const int MOD = 1000000007;


int main(){
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll res = INF;
    //たかだか3パターンしかないので全部やってみる
    
    //Aピザ,Bピザを買う
    res = min(res, a * x + b * y);

    //ABピザをmin(a,b)枚買って、残りを買う
    ll abmin = min(x,y);
    ll tmp;
    tmp = c * 2 * abmin;
    ll zan;
    if(x > y)zan = (x-y)*a;
    else zan = (y-x)*b;

    res = min(res, tmp + zan);

    //ABピザをmax(a,b)枚買う
    res = min(res, c * 2 * max(x,y));

    cout << res << endl;
    return 0;

}