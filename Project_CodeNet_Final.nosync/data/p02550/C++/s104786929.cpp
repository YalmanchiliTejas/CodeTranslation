#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=998244353;

template<typename T> bool chmax(T &a,const T b){if(a < b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,const T b){if(a > b){a=b; return true;} return false;}


int main(){
    ll N, X, M; cin >> N >> X >> M;
    ll tmp=X;
    vector<bool> check(M, 0);
    vi ord(M, -1);
    ll n, m, cnt=1;
    while(1){
        if(check[tmp]){
            n=ord[tmp];
            m=cnt;
            break;
        }
        check[tmp]=true;
        ord[tmp]=cnt;
        cnt++;
        tmp=tmp*tmp%M;
    }

    ll ans=0;
    if(N <= m){
        for(ll i=1; i<=N; i++){
            ans+=X;
            X=X*X%M;
        }
    }
    else{
        ll sum1=0, sum2=0, sum3=0;
        tmp=X;
        for(ll i=1; i<=n-1; i++){
            sum1+=tmp;
            tmp=tmp*tmp%M;
        }
        for(ll i=n; i<m; i++){
            sum2+=tmp;
            tmp=tmp*tmp%M;
        }
        for(ll i=1; i<=(N-n+1)%(m-n); i++){
            sum3+=tmp;
            tmp=tmp*tmp%M;
        }
        ans=sum1+sum2*((N-n+1)/(m-n))+sum3;
    }
    cout << ans << endl;
    return 0;
}