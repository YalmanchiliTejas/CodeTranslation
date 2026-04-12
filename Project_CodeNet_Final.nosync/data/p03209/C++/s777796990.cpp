#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <complex> // complex<double> a(1.2 , 2.3);// real(): 1.2, imag()2.3
using namespace std;

#define MOD 1000000007
#define ll long long
#define ld long double
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rmsame(a) sort(all(a)),a.erase(unique(all(a)), a.end())
#define rmvector(a,b) rep(i,a.size())rep(j,b.size())if(a[i]==b[j]){a.erase(a.begin()+i);i--;break;}
#define pq_pair_tB priority_queue <pair<ll,ll>, vector<pair<ll,ll> > , greater<pair<ll,ll> > >
#define pq_pair_ts priority_queue <pair<ll,ll> > //第二成分の大きさが関係ない
template<typename X> bool exist(vector<X> vec, X item){return find(all(vec), item)!=vec.end();}
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

ll all_num[51];
ll p_num[51];

void func(){
    rep(i, 51){
        if(i == 0){
            all_num[0] = 1;
            p_num[0] = 1;
        }else{
            all_num[i] = all_num[i-1]*2+3;
            p_num[i] = p_num[i-1]*2 + 1;
        }
    }
}

ll cal(ll N,ll X){
    if(N == 0){
        if(X == 1) return 1;
        if(X == 0) return 0;
    }
    /*
    B
    N-1
    P
    N-1
    B
    */
    if(X == 1){ return 0 ;}
    else if(1 < X && X <= (1 + all_num[N-1])){return cal(N-1, X-1);}
    else if(X == (2 + all_num[N-1])){return 1LL + p_num[N-1];}
    else if( (2 + all_num[N-1]) < X && X <= (2 + 2*all_num[N-1])){return p_num[N-1] + 1LL + cal(N-1, X-2-all_num[N-1]);}
    else if( X == (3 + 2*all_num[N-1])){return p_num[N];}

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    func();
    ll N , X;
    cin >> N >> X;

    ll ans = cal(N,X);

    cout << ans << endl;

    //cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
