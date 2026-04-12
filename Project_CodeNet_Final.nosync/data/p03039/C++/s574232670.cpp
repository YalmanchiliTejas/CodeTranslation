#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;

class UnionFind{
private:
    vector<int> Parent;
public:
    UnionFind(int N){
        vector<int> Parent(N,-1);
    }

    int root(int A){
        if(Parent[A]<0) return A;
        return Parent[A]=root(Parent[A]);
    }

    int size(int A){
        return -Parent[root(A)];
    }

    bool connect(int A,int B){
        A=root(A);
        B=root(B);
        if(A==B) return false;
        if(size(A)<size(B)) swap(A,B);
        Parent[A]-=Parent[B];
        Parent[B]=A;
    }
};

typedef long long ll;
const int division = 1000000007;
vector<ll> fac; //n!(mod M)
vector<ll> ifac; //k!^{M-2} (mod M)


ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % division;
        x = x*x % division;
        n = n >> 1;
    }
    return ans;
}

ll cmb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    fac.push_back(1);
    ifac.push_back(1);
    for(ll i = 0; i<a; i++){
        fac.push_back(fac[i]*(i+1) % division); // n!(mod M)
        ifac.push_back(ifac[i]*mpow(i+1, division-2) % division); // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
    ll tmp = ifac[a-b]* ifac[b] % division;
    return tmp * fac[a] % division;
}
typedef pair<int, int> P;

int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    ll ans=0;
    for(int i=1;i<M;i++){
        ans += i*(M-i)*(N*N);
    }
    for(int i=1;i<N;i++){
        ans += i*(N-i)*(M*M);
    }
    ans%=division;
    ans *= cmb(N*M-2,K-2)%division;
    cout << ans%division << endl;
}
