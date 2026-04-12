#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
 
#define VV(T) vector<vector< T > >
 
template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  reep(i,0,n)
#define clr(a) memset((a), 0 ,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define PB push_back

const int INF = (1e9);
const ll MOD = 1e9+7;
const double EPS = 1e-5;
const double PI=atan2(0,-1);



int main(void){
    int n;
    string s;
    vint cnt = vint(26);
    rep(i,26){
        cnt[i] = INF;
    }
    cin >> n;
    rep(i,n){
        cin >> s;
        vint temp = vint(26);
        rep(i,s.size()){
            temp[(int)(s[i]-'a')]++;
        }
        rep(i,26){
            if(cnt[i] > temp[i]){
                cnt[i] = temp[i];
            }
        }
    }
    int sum=0;
    rep(i,26){
        rep(j,cnt[i]){
            cout << (char)('a' + i);
        }
    }
    cout << endl;
}