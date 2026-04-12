#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define MOOD 1000000007

using namespace std;
using ll = long long;
using P = pair<int,int>;

int cmpnum(const void *a, const void *b)
{
    long long *A = (long long *)a;
    long long *B = (long long *)b;
    if (*A > *B)
        return 1;
    if (*A < *B)
        return -1;
    return 0;
}

int char_sort_max( const void * a , const void * b ) {
    return strcmp(( char * )a , ( char * )b );
}

int char_sort_min( const void * a , const void * b ) {
    return strcmp(( char * )a , ( char * )b );
}

int gcd(int x, int y)
{
    int t;

    while (y != 0) {
        t = x % y;  x = y;  y = t;
    }
    return x;
}

struct UnionFind{
    vector<int> d;
    UnionFind(int n = 0):d(n,-1){};

    int find(int x){
        if(d[x] < 0) {
            return x;
        }
        else{
            return d[x] = find(d[x]);
        }
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);

        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
    int size(int x){
        return -d[find(x)];
    }

};

struct mint {
    ll x;

    mint(ll x) : x((x % MOOD + MOOD) % MOOD) {}

    mint operator-() const { return mint(-x); }

    mint &operator+=(const mint a) {
        if ((x += a.x) >= MOOD) x -= MOOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOOD-a.x) >= MOOD) x -= MOOD;
        return *this;
    }

    mint &operator*=(const mint a) {
        if ((x *= a.x) %= MOOD);
        return *this;
    }

    mint operator+(const mint a)const {
        mint res(*this);
        return res += a;
    }

    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }

    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }

    mint pow(ll t) const{
        if(!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if(t&1) a *= *this;
        return a;
    }

    mint inv() const {
        return pow(MOOD-2);
    }

    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }

    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }

};

mint kaijyo(int n) {
    if (n == 0) return 1;
    mint x = kaijyo(n/2);
    x *= x;
    if (n%2 == 1) x *= 2;
    return x;
}

mint choose(int n, int a) {
    mint x = 1, y = 1;
    rep(i,a) {
        x *= n-i;
        y *= i+1;
    }
    return x / y;
}


int shakutori(ll x, ll n,ll k, ll a[])
{
    long long int ai,res,ok,ng,mid;
    res = 0;
    for (int i = 0; i < n; i++)
    {
        // printf("%lld\n", res);
        ai = a[i];
        if(ai == 0){
            if(x < 0){
                res += 0;
            } else {
                res += n - 1;
            }
        } else
        {
            if(ai <= -1){
                if (ai * ai <= x){
                    res -= 1;
                }
                ok = n;
                ng = -1;
                while (ok-ng>1)
                {
                    mid = (ok + ng) / 2;
                    if(a[mid]*ai<=x){
                        ok = mid;
                    } else {
                        ng = mid;
                    }
                }
                res += n - ok;
            } else
            {
                if (ai * ai <= x)
                {
                    res -= 1;
                }
                ok = -1;
                ng = n;
                while (ng - ok > 1)
                {
                    mid = (ok + ng) / 2;
                    if (a[mid] * ai <= x)
                    {
                        ok = mid;
                    }
                    else
                    {
                        ng = mid;
                    }
                }
                res += ok + 1;
            }

        }
    }
    // printf("%lld\n", res);
    return k <= res / 2;
}


int main() {
    ll N,K;
    scanf("%lld %lld",&N,&K);
    if(N==K){
        printf("Yes");
    }
    else{
        printf("No");
    }
}
