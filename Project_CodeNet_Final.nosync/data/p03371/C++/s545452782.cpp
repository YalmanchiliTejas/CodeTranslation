#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>

template<typename T> bool chmax(T &a,T b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

template<typename T> bool chmin(T &a,T b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}

using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=1001001000;
const ll LLMAX=1010010010010010000;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    
    ll price;
    if(2*C>A+B) price=A*X+B*Y;
    else{
        if(X>Y){
            if(2*C>A)price=2*C*Y+A*(X-Y);
            else price=2*C*X;
        }else{
            if(2*C>B)price=2*C*X+B*(Y-X);
            else price=2*C*Y;
        }
    }
    printf("%lld\n",price);
    
    return 0;
}
