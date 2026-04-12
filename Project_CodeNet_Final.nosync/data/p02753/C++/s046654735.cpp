#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rrep(i,n) for(ll i=(n);i>=0;i--)
template<typename T =ll> using v = vector<T>;
template<typename T =ll> using vv = v<v<ll>>;
template<typename T=ll,typename U=ll> using p = pair<T,U>;
template<typename T> T chmin(T &a,T b) {return a=min(a,b);}
template<typename T> T chmax(T &a,T b) {return a=max(a,b);}
const ll INF = (ll)1e9;

void a(){
    string s; cin >> s;
    if(s.find("A")==string::npos){
        cout << "No";
    }else if(s.find("B")==string::npos){
        cout << "No";
    }else{
        cout << "Yes";
    }
}


void b(){

}

int main(){
    a();
    return 0;
}
