// Author: Moulik
// Date Created: 30 August 2020
// Filename: AT177C.cpp
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define what_is(x) cerr << "DEBUG::BEGIN\n\tVariable name:\n\t\t" << #x << "\n\tdata:\n\t\t" << x << "\nDEBUG::END" << endl;
#else
#define what_is(x) ;
#endif

// CUSTOM FUNCTIONS

// Power using binary exponentation
long long power(long long base, int exponent){ 
    long long ans = 1;
    while(exponent > 0){ 
        if (exponent&1) 
            ans = (ans*base); 
        exponent >>= 1;
        base = base*base;
    }
    return ans; 
} 

// Power modulo p using binary exponentation
long long power(long long base, int exponent, int p){ 
    long long ans = 1;
    base = base%p;
    while(exponent > 0){ 
        if (exponent&1) 
            ans = (ans*base)%p; 
        exponent >>= 1;
        base = (base * base) % p; 
    } 
    return ans; 
}

// Return n^-1%p, given p is prime
int modInverse(int n, int p){
    return power(n,p-2,p);
}

// calculates factorial from 0 to n (inclusive)
void factorialCalc(vector<int> & factorial, int n){
    if(factorial.size()!=n+1){factorial.resize(n+1);}
    factorial[0]=1;
    factorial[1]=1;
    for(int i = 2; i <=n; i++){
        factorial[i] = factorial[i-1]*i;
    }
}

// calculates factorial mod p from 0 to n (inclusive) 
void factorialCalc(vector<int> & factorial, int n, int p){
    if(factorial.size()!=n+1){factorial.resize(n+1);}
    factorial[0]=1;
    factorial[1]=1;
    for(int i = 2; i <=n; i++){
        factorial[i] = (factorial[i-1]*1ll*i)%(p);
    }
}

// calculates nCr mod p, using fermats method, given p is prime.
unsigned long long nCr(unsigned long long n, int r, int p, vector<int> & fac){ 
    if (r == 0) 
        return 1; 
    return (1ll*fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
}

// Sorts array in the given order {key is 0 indexed}
template <typename T>
void keySort(vector<T> &arr, vector<int> &key){
    int n = arr.size();
    if(key.size()!=n){
        throw runtime_error("Size of data array not equals to size of key array");
    }
    vector<T> ans(n);
    int ar[n];
    for(int i = 0; i < n; i++){
        ar[key[i]]=i;
    }
    for(int i = 0; i < n; i++){
        ans[i] = arr[ar[i]];
    }
    arr = ans;
}

#define rprint(data) std::cout << data;return  
#define rprintln(data) std::cout << data << endl;return  

#define selfMin(x, y) x=std::min(x,y);
#define selfMax(x, y) x=std::max(x,y);

// OSTREAMS

template<typename T1, typename T2>
ostream & operator<<(ostream &os, const pair<T1,T2> p){
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

template<typename T>
ostream & operator<<(ostream &os, const vector<T> p){
    os << "{ ";
    for(auto i:p){
        os << i << ",";
    }
    os << "\b";
    os << "}";
    return os;
}

// ISTREAMS

template<typename T1, typename T2>
istream & operator >> (istream &in, pair<T1,T2> & p){
    in >> p.first >> p.second;
    return in;
}

void solve();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}


void solve(){
    int n;
    const int MOD = 1e9+7;
    cin >> n;
    vector<long long> vc(n+1,0);
    for(int i = 0; i < n; i++){
        cin >> vc[i];
    }
    vector<long long> cmv(n,0);
    cmv[0] = vc[0];
    for(int i = 1; i < n; i++){
        cmv[i] = (vc[i]+cmv[i-1])%MOD;
    }

    long long ans = 0;
    for(int i = 0; i < n-1; i++){
        ans = (ans+(vc[i] * ((MOD+cmv[n-1]-cmv[i]))%MOD)%MOD)%MOD;
    }
    rprintln(ans);
}
