#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a/gcd(a, b) * b;
}

int main()
{
    cout << fixed << setprecision(15);
    ll N, X, M;
    cin >> N >> X >> M;

    map<ll ,ll> T;

    vector<ll> A;

    ll ans = 0;
    ll now;
    ll d = 0;
    ll count = 0;
    ll loop = 0;
    ll start = 0;
    ll end = 0;
    bool check = false;
    for(ll i=1; i<=min(N, M); i++){
        // cout << i << endl;
        if(check == true && count == d) break;
        if(i==1){
            now = X;
            ans += X;
            T[now] = i;
            continue;
        }
        now = (now*now) % M;

        // nowがすでに存在しているなら
        if(check == false && (T[now] > 0)){
            // cout << "end" << endl;
            check = true;
            start = T[now];
            end = i;
            d = i - T[now] - 1;
            A.resize(d);
            continue;
        }
        T[now] = i;

        if(check){
            if(count == 0){
                A[count] = now;
            }
            else{
                A[count] = A[count-1] + now;
            }
            count++;
        }
    }

    ans = 0;
    if(check == false){
        for(ll i=1; i<=min(N, M); i++){
            if(i==1){
                now = X;
                ans += now;
            }
            else{
                now = (now*now) % M;
                ans += now;
            }
        }
        cout << ans << endl;
        return 0;
    }

    // cout << start << " " << end << endl;
    ll dis = end-start;

    vector<ll> B(end+1, 0);

    ans = 0;
    for(ll i=1; i<=end; i++){
        if(i==1){
            now = X;
            ans += now;
            B[i] = X;
        }
        else{
            now = (now*now) % M;
            ans += now;
            B[i] = B[i-1] + now;
        }
    }
    ans += ((N-end)/dis) * (B[end] -B[start]);

    if((N-end) % dis != 0){
        ll c = (N-end) % dis;
        ans += B[start+c] - B[start];
    }
    cout << ans << endl;

    return 0;
}