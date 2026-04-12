#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD = 1000000007;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ALL(a) begin(a),end(a)
#define COUNTOF(a) (sizeof(a)/sizeof(a[0]))
#define SP << " " <<
#define FMT(a) #a<<":"<<a 
#define FMT2(a,b) #a<<":"<<a<<", "<<#b<<":"<<b 
#define FMT3(a,b,c) #a<<":"<<a<<", "<<#b<<":"<<b<<", "<<#c<<":"<<c 
#define FMT4(a,b,c,d) #a<<":"<<a<<", "<<#b<<":"<<b<<", "<<#c<<":"<<c<<", "<<#d<<":"<<d 
template<class T> istream& operator >> (istream& s, vector<T>& v) {
  for (T& x: v) s >> x;
  return s;
}
void yes(bool f){cout<<(f?"yes":"no")<<endl;}
void Yes(bool f){cout<<(f?"Yes":"No")<<endl;}
void YES(bool f){cout<<(f?"YES":"NO")<<endl;}
#define ANS(a) cout<<a<<endl


int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //cout<<std::fixed<<std::setprecision(10);

    int H, W; cin >> H >> W;
    vector<string> v;;

    rep(i, H) {
        string s;
        cin >> s;
        if (!all_of(ALL(s), [](char x){return x=='.';}))
            v.push_back(s);
    }

    rep(j, W) {
        bool all_white = true;
        rep(i, v.size()) {
            if (v[i][j] != '.') {
                all_white = false;
                break;
            }
        }
        if (all_white) {
            rep(i, v.size()) {
                v[i].erase(j, 1);
            }
            j--;
        }
    }
    rep(k, v.size())
        cout << v[k] << endl;
    
}
