#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

typedef unsigned long long ull;
const ull MOD = 1e9+7;
struct Dice{
    ll s[6];
    void roll(char c){
        //the view from above
        // N
        //W E
        // S
        //s[0]:top
        //s[1]:south
        //s[2]:east
        //s[3]:west
        //s[4]:north
        //s[5]:bottom
        ll b;
        if(c=='E'){
            b=s[0];
            s[0]=s[3];
            s[3]=s[5];
            s[5]=s[2];
            s[2]=b;
        }
        if(c=='W'){
            b=s[0];
            s[0]=s[2];
            s[2]=s[5];
            s[5]=s[3];
            s[3]=b;
        }
        if(c=='N'){
            b=s[0];
            s[0]=s[1];
            s[1]=s[5];
            s[5]=s[4];
            s[4]=b;
        }
        if(c=='S'){
            b=s[0];
            s[0]=s[4];
            s[4]=s[5];
            s[5]=s[1];
            s[1]=b;
        }
        
        // migi neji
        if(c=='R'){
            b=s[1];
            s[1]=s[2];
            s[2]=s[4];
            s[4]=s[3];
            s[3]=b;
        }
        
        if(c=='L'){
            b=s[1];
            s[1]=s[3];
            s[3]=s[4];
            s[4]=s[2];
            s[2]=b;
        }
        
    }
    ll top() {
        return s[0];
    }
    ull hash(){
        ull res=0;
        for(int i=0;i<6;i++) res=res*MOD+s[i];
        return res;
    }
};
vector<Dice> makeDices(Dice d){
    vector<Dice> res;
    for(int i=0;i<6;i++){
        Dice t(d);
        if(i==1) t.roll('N');
        if(i==2) t.roll('S');
        if(i==3) {t.roll('S'); t.roll('S');}
        if(i==4) t.roll('L');
        if(i==5) t.roll('R');
        for(int k=0;k<4;k++){
            res.push_back(t);
            t.roll('E');
        }
    }
    return res;
}

int n;
ll solve(){
    ll res = 1;
    Dice d; iota(d.s,d.s+6,1);
    while(n--){
        string s; cin >> s;
        d.roll(*s.begin());
        res += d.top();
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    while(cin >> n,n){
        cout << solve() << endl;
    }
    return 0;
}

