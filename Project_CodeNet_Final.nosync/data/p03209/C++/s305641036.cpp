#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPL(i,a,n) for(ll i=a;i<n;++i)
#define RUP(a,b) ((a+b-1)/(b))
#define ENT "\n"
#define SORTVG(v) sort(v.begin(),v.end(),greater<>())
#define SORTV(v) sort(v.begin(),v.end())
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define int long long

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;

template<class T> void chmax(T& a, T b) {if(a < b){a=b;}}
template<class T> void chmin(T& a, T b) {if(a > b){a=b;}}
template<class T> void YesNo(T& a) {if(a){cout << "Yes" << ENT;}else{cout << "No" << ENT;}}
template<class T> void YESNO(T& a) {if(a){cout << "YES" << ENT;}else{cout << "NO" << ENT;}}
template<class T> void AorB(T& a, string A,string B) {if(a){cout << A << ENT;}else{cout << B << ENT;}}

int layer(int level){
    return pow(2,level+2)-3;
}

int burger(int level,int x){
    if(level==0) return 1;
    else if(x==1) return 0;
    else if(1<x && x<=layer(level-1)+1) return burger(level-1,x-1);
    else if(x==layer(level-1)+2) return burger(level-1,layer(level-1))+1;
    else if(layer(level-1)+2<x && x<layer(level)) return burger(level-1,layer(level-1))+1+burger(level-1,x-layer(level-1)-2);
    else if(x==layer(level)) return burger(level-1,layer(level-1))*2+1;
    else return -1;
}

void atcoder(){
    int n,x;
    cin>>n>>x;
    cout<<burger(n,x)<<ENT;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    atcoder();
    return 0;
}
