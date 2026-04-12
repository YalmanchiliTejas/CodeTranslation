#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long int ll;

#define MOD 998244353


ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

bool primeNumber(ll n){
    if(n < 2) return false;
    else{
        for(ll i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
}
  
  

int main(){
    char c;
    cin >>c;
    
    if (c == 'a' || c == 'e' ||c == 'i' ||c == 'o' ||c == 'u')cout << "vowel" << endl;
    else cout << "consonant" << endl;
    
    return 0;
}

