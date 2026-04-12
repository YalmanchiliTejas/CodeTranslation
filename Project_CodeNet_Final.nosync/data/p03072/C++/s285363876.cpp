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
    cout<<std::fixed<<std::setprecision(10);

    int N; cin >>N;
    vector<int> H(N); cin >> H;
    
    int ans = 1;

    for (int i = 1; i < N; i++) {
        bool ok=true;
        for (int j = 0; j < i; j++) {
            if (H[j] > H[i]) {
                ok = false;
                break;
            }   
        }
        if (ok) ans++;
    }

    cout << ans << endl;
}
