#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
//#include <atcoder/all>
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef int64_t lint;
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using lb = long double;
//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
//xにはvectorなどのコンテナ
#define all(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SI(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(all(x)) //最大値を求める
#define MIN(x) *min_element(all(x)) //最小値を求める
#define debug(x) cerr << #x << ": " << x << "\n"//手動デバッグ
#define debugV(x) for(int i=0;i<((ll)(x).size());i++)cerr << #x <<"at:"<<i<< ": " << x[i] << "\n"//手動デバッグ 
#define YES(c) cout<<((c)?"YES\n":"NO\n"),0
#define Yes(c) cout<<((c)?"Yes\n":"No\n"),0
#define O(p) cout<<p<<"\n",0
#define OS(p) cout<<p<<" ",0
#define ON(p) cout<<p,0
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define inf 2147483647 //int値の最大値
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
#define endl "\n"//endlを置き換える
//略記
#define pb emplace_back //vectorヘの挿入
#define mp make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定

const int dy[4]={1,0,-1,0};
const int dx[4]={0,1,0,-1};//^>v<

template<class T=int> T in(){
    T x;
    cin>>x;
    return (x);
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int gcd(int a, int b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int two(int n){
	ll ans=1;
	rep(i,n){
		ans*=2;
	}
	return ans;
}
int up_b(vector<ll> v,ll i){
    int itr=upper_bound(all(v),i)-v.begin();
    if(itr==v.size()){
        return -1;
    }else{
        return itr;
    }
}
int lo_b(vector<ll> v,ll i){
    int itr=lower_bound(all(v),i)-v.begin();
    if(itr==v.size()){
        return -1;
    }else{
        return itr;
    }
}
//------------------------------------------------------------

//------------------------------------------------------------
int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
//------------------------------------------------------------
    int n;cin>>n;
    vector<ll> v(0);
    rep(i,n){
        ll hoge;cin>>hoge;
        if(i==0){
            v.pb(-hoge);
        }else{
            int itr=up_b(v,-hoge);
            if(itr==-1){
                v.pb(-hoge);
            }else{
                v[itr]=-hoge;
            }
        }
    }
    
    
    
    O(v.size());
    
    
    
    
//------------------------------------------------------------
	return 0;
}
