#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>;
#define vvec(s) vector<vector<s>> ;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(),s.end()
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
long long int mod=1000000007;
struct modint{
    long long int x;
    modint(long long int x=0):x(x%mod){}//メンバ変数を初期化する。
    modint& operator+= (const modint a){
        if((x+=a.x)>=mod){x-=mod;}//%は遅い
        return *this;//関数を終了するためにはreturnを返さなければならないが、return aとでもするとその値が代入されてしまう。そこで、計算された後の自分自身のアドレス、つまり何もしないようにしている？
    }
    modint& operator-= (const modint a){
        if((x+=mod-a.x)>=mod) x-=mod;
        return *this;
    }
    modint& operator*= (const modint a){
        x*=a.x;
        x%=mod;
        return *this;
    }
    modint operator+(const modint a) const{//引数の横のconstは関数自体がconstつまりメンバ変数の変更ができなくなるということ。バグ防止に役立つ
        modint copy(*this);//constがあるのでメンバ変数をいじれないから値だけコピーする
        return copy+=a;
    }
    modint operator-(const modint a)const{
        modint copy(*this);
        return copy-=a;
    }
    modint operator*(const modint a)const{
        modint copy(*this);
        return copy*=a;
    }
    modint pow(long long int t)const{//繰り返し二乗法
        if(t==0) return 1;
        modint a=pow(t>>1);//tを1/2倍したものの累乗
        a*=a;//aを二乗する
        if(t&1) a*=*this;//ビット形式での一桁目が1、つまりtが奇数ならば、もう一回掛ける。
        return a;
    }
    modint inv() const{
        return pow(mod-2);
    }
    modint operator/=(const modint a){
        return (*this)*=a.inv();
    }
    modint operator/(const modint a){
        modint copy(*this);
        return copy/=a;
    }
};




//ここから
struct combination {
    vector<modint> fact,ifact;//階乗＝factoria
    combination(lli n):fact(n+1),ifact(n+1){//fact=階乗、ifactはその逆元
        fact[0]=1;//0!=1
        for(lli i=1;i<=n;i++) fact[i]=fact[i-1]*i;
        ifact[n]=fact[n].inv();//invは計算が重いので一回で済ませたい
        for(lli i=n;i>=1;i--) ifact[i-1]=ifact[i]*i;
    }
    modint operator()(lli n,lli k){
        if(k<0||k>n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
};
//modintで足し算、引き算を扱う場合余りを扱っている関係上負の値になりえない問題でも
//負の値になることがあるので、そこのフォローをする！
int main(){
    modint n,m,k,ans;
    cin>>n.x>>m.x>>k.x;
    modint i;
    modint s;
    s.x=1;
    combination c(n.x*m.x);
    for(i.x=1;i.x<=(n.x);i.x++){
        ans+=(n-i)*m*m*i;
    }
    for(i.x=1;i.x<=(m.x);i.x++){
        ans+=(m-i)*n*n*i;
    }
    ans*=c((n*m-s-s).x,(k-s-s).x);
    out(ans.x);
}