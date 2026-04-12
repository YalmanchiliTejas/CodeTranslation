#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
const int MOD = 1000000007;


typedef long long int ll; 
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

void floatOutPutSetup(){
    cout << fixed;
    cout << setprecision(10);
}

int main(){
    string s;
    bool a=false,b=false;
    cin>>s;
    rep(i,s.size()){
        if(s[i]=='A')a=true;
        if(s[i]=='B')b=true;
    }
    if(a&&b)cout<<"Yes";
    else cout<<"No";

    return 0;
}