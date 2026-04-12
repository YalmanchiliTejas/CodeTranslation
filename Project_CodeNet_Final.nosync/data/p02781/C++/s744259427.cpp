#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

long long pow(long long N, long long k) {
    long long res = 1;
    for (int i = 0; i < k; ++i) res *= N;
    return res;
}


long long combination(long long N, long long R){
    if (R < 0 || R > N) return 0;
    if (R == 1) return N;
    else if (R == 2) return N * (N-1) / 2;
    else return N * (N-1) * (N-2) / 6;
}


string N;
ll K;

// i桁目まで見たとして、残りがk回0以外を入れられていて、未満確定ならsmallerはtrueで答えを出す。
ll solve(ll i,ll k,bool smaller) {
    // 途中だがkが0になった。(=残りの桁があっても、0で埋まるので1を返す)
    if (k == 0) return 1;

    // 最後の桁まで走査した(= 最後の桁まで決定した && k != 0 なので 0を返す)
    if ( i == N.size()) return 0;

    // N未満であることが確定しているならば残りの桁は何でも入るので組み合わせを使って返す
    if (smaller) return combination(N.size()-i,k) * pow((ll)9,(ll)k);

    // まだ未満とは限らない場合

    // 今見ている桁に相当するNの値が0なら先に進む。
    if (N[i] == '0') return solve(i+1,k,false);

    // N[i]が0でない場合、 その桁には0,1,...と入る可能性がある。
    // i桁目に0を入れた場合の個数 (明らかにN以下の値になるためフラグはtrueになる)
    auto zero = solve(i+1,k,true);
    // i桁目に0<k<N[i]を満たす様な値を入れた場合(明らかにN以下の値になるためフラグはtrueになる)
    // N[i] == 1ならmidはないし、N[i] == 3ならmidはN[i] == 1,2のことになるので適宜調整をする。
    auto mid =  solve(i+1,k-1,true) * (N[i]- '1');
    // i桁目にN[i]を入れた場合
    auto last = solve(i+1,k-1,false);

    return zero + mid + last;

}

int main() {

    cin >> N;

    cin >> K;


    cout << solve(0,K, false) << endl;
    return 0;
}
