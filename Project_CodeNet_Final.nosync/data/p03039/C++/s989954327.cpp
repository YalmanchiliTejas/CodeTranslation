#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define _dec(i,j,N) for(int i = (N-1);i >= (j);i--)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define LL long long

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v) {
    _for(i,0,v.size()) os << v[i] << " ";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){
    for(typename set<T>::iterator it = v.begin();it != v.end();it++)
    os << *it <<" ";
    return os;
}


const int maxn = 1e5+5;
const int mod = 1e9+7;
int mult(int a,int b){return ((LL)a*(LL)b)%mod;}
int add(int a,int b){return ((LL)a + (LL)b)%mod;}

int fast_pow(int a,int b){
    if(b == 0) return 1;
    int res = fast_pow(a,b/2);
    res = mult(res,res);
    if(b&1) res = mult(res,a);

    return (int)res;
}


int N,M,K;

LL fac[maxn*2];

void init(){
    fac[0] = 1;
    _for(i,1,maxn*2){
        fac[i] = mult(fac[i-1],i);
    }
}

int com(int a,int b){
    if(a <= 0 || b <= 0 || a-b <= 0) return 1;
    int k = fac[a];
    int k2 = mult(fast_pow(fac[a-b],mod-2),fast_pow(fac[b],mod-2));
    return mult(k,k2);
}



int main()
{
    init();
    cin >> N >> M >> K;
    int res = 0;

    int k1 = com(M*N-2,K-2);
    //cout << k1 << endl;
    int MM = mult(M,M);
    int NN = mult(N,N);

    _for(d,1,N){
        res = add(res,mult(d,mult(k1,mult(N-d,MM))));
    }
    _for(d,1,M){
        res = add(res,mult(d,mult(k1,mult(M-d,NN))));
    }

    cout << res << endl;
    return 0;
}
