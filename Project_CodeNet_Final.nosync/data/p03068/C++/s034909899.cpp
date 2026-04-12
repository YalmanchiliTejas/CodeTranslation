/*
 Author : Bisma
 @ copy from bisma template 1.0
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>
#include <fstream>
#include <cstdio>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define repn(a,b,c) for(int a=b; a>=c; a--)
#define ll long long
#define mem(a, b) memset(a, (b), sizeof(a))
#define loop(a,b,c) for(int a = b ;a<c;a++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;

ll max(ll a, ll b){
    if(a>b) return a;
    return b;
}

ll min(ll a, ll b){
    if(a>b) return b;
    return a;
}

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}



int main(){
    fast();

    
    string s,a;

    ll n;


    s = "0";

    cin>>n>>a;

    ll k;

    cin>>k;

    s+=a;

    char p = s[k];


    rep(i,1,n){
        if(s[i]!=p){
            cout<<"*";
        }else{
            cout<<s[i];
        }
    }

    cout<<endl;

    return 0;
    
}
 




