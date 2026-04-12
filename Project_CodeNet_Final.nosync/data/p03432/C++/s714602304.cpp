#include <bits/stdc++.h>
#define ll long long

const int maxn = 200100;
const int maxbit = 30;
const ll base = 998244353;

using namespace std;

ll fact[maxn],finv[maxn],f[maxn],res;
int N,M;

ll sum(ll x,ll y) {
    return (x+y)%base;
}

ll sub(ll x,ll y) {
    return (x-y+base)%base;
}

ll power(ll a,ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % base;
        }
        a = a * a % base;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return power(a,base-2);
}

ll C(int k,int n) {
    if (n<k) return 0;
    return (fact[n] * finv[k]) % base * finv[n-k] % base;
}

void checking_primitive_roots() {
    ll p = base-1; //2^23*7*17
    ll a[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for (int i=0;i<=9;i++) {
        cout<<power(a[i],p/2)<<" ";
        cout<<power(a[i],p/7)<<" ";
        cout<<power(a[i],p/17)<<" ";
        cout<<endl;
    }
}

struct ntt {
    int r = 3; // primitive roots of base

    int revBit(int x,int nbit) {
        int i=0,j=nbit-1;
        while (i<=j) {
            if ( ((x>>i) & 1) !=((x>>j) & 1)) {
                x^=1<<i;
                x^=1<<j;
            }
            i++; j--;
        }
        return x;
    }

    void _fft(vector<ll> &a, int eq) {
        int n = a.size();
        int nbit = (int)(log(n) / log(2));
        ll wn = power(r,(base-1)/n);
        if (eq==1) wn = inv(wn);
        for (int i=0;i<n;i++) {     //bit reverse
            int j = revBit(i,nbit);
            if (i<j) swap(a[i],a[j]);
        }
        for (int step = 1;step<n;step*=2) {
            ll w = 1;
            ll next = power(wn,n/(2*step));
            for (int i=0;i<step;i++) {
                for (int start=i;start<n;start+=2*step) {
                    ll u = a[start];
                    ll v = w * a[start+step] % base;
                    a[start] = sum(u,v);
                    a[start+step] = sub(u,v);
                }
                w = w * next % base;
            }
        }
        for (int i=0;i<n;i++) if (a[i]<0) a[i] = sum(a[i],base);
    }

    void fft(vector<ll> &input) {
        _fft(input,0);
    }

    void ifft(vector<ll> &input) {
        _fft(input,1);
        int n = input.size();
        for (int i=0;i<n;i++) input[i] = (input[i] * inv(n)) % base;
    }

    vector<ll> multiply(vector<ll> p, vector<ll> q) {
        int nbase = 1;
        while (nbase < p.size() + q.size()) nbase*=2;
        vector<ll> _p = p, _q = q;
        _p.resize(nbase); _q.resize(nbase);
        fft(_p);
        fft(_q);
        for (int i=0;i<nbase;i++) _p[i] = _p[i] * _q[i] % base;
        ifft(_p);
        return _p;
    };

};

ntt dft;


int main() {
    ios_base::sync_with_stdio(0);
   // freopen("in.txt","r",stdin);
    cin>>N>>M;
    fact[0] = 1; fact[1] = 1;
    finv[0] = 1; finv[1] = 1;
    for (int i=2;i<maxn;i++) {
        fact[i] = (fact[i-1] * 1ll* i) % base;
        finv[i] = inv(fact[i]);
    }
    f[0]=1;
    for (int k=0;k<M;k++) {
        vector<ll> p,q;
        for (int i=0;i<=N;i++) p.push_back(f[i] * finv[i] % base);
        for (int i=0;i<=N;i++) q.push_back(finv[i+2]);
        vector<ll> c = dft.multiply(p,q);
        for (int i=0;i<=N;i++) f[i] = sub(c[i]*fact[i+2] % base, f[i]*1ll*i %base);
       // for (int i=0;i<=N;i++) cout<<f[i]<<" ";
      //  cout<<endl;
    }
    res=0;
    for (int i=0;i<=N;i++) res = sum(res,f[i]*C(i,N) % base);
    cout<<res;

}


