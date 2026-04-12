// https://ynucpc.github.io/blog/2018/04/15/cp_vscode/
// http://www.atmarkit.co.jp/ait/articles/1509/08/news019.html

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << (x) << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

// 配列の総和
// greater


ll big(ll n){
    return (1ll << n) * 4 - 3;
}
ll pa(ll n){
    return (1ll << n+1) - 1;
}
int main(){
    ll N, X;
    cin >> N >> X;
    ll ans = 0;
    for(int i=N; i>=0; i--){
        ll bg = big(i);
        //show(bg);
        //show(ans);
        if (bg>>1 < X){
            ans += pa(i-1) + 1;
            X -= (bg>>1) + 1;
        }else if (bg>>1 == X){
            ans += pa(i-1);
            break;
        }else{
            X -= 1;
        }

    }
    cout << ans << endl;

}


