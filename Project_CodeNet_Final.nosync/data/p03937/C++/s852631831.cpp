#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define push push_back
#define solve(a) ((a) ? "Possible" : "Impossible ")
    typedef vector<long long>
        V;
typedef vector<V> VV;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<61;
const int INF = 1<<30;
int main(){
    int h,w;
    cin >> h >> w;
    vector<string>a(h+1,"");
    bool ans=false;
    int c=0;
    rep(i,h){
        cin>>a[i];
        rep(j,w){
            if(a[i][j]=='#'){
                c++;
            }
        }
    }
   // cout<<c<<endl;
    cout<<solve(c==h+w-1)<<endl;
}