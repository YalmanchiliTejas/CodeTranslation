#include "bits/stdc++.h"
using namespace std;
#define INF 1e9
#define rep(i, n) for(int i = 0; i < n; i++)
#define ALL(x) (x).begin(), (x).end()  //昇順
#define RALL(x) (x).rbegin(), (x).rend() // 降順
const long long mod = 1e9+7;
typedef priority_queue<int> PQ;
typedef vector<long long> VL;
typedef vector<int> VI;  // VI a(n);
typedef vector<string> VS;  
typedef vector<char> VC; 
typedef vector<VS> VSS;
typedef vector<VC> VCC;    
typedef vector<VI> VII;   // VII a(n,vector<int>(m)) n * m 
typedef vector<VL> VLL;
typedef pair<int, int> PII;
typedef map<int, int> MP;   //MP a;
typedef vector<pair<int, int> > PS;
typedef long long ll;  //ll とdoubleは違う
template <class T>  // chmax(max, a);
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> //chmin(min,a)
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template<typename T>   // operator << (cout,a);
ostream& operator << (ostream& os, vector<T>& v) {
    os << "{";
    rep(i, (int)v.size()) { os << v[i] << (i < v.size() - 1 ? ", " : ""); }
    os << "}";
    return os;
}

// g++ -std=c++11 prac.cpp
ll Max=-1e9,Min=1e9+1;
 
int main(){
    ll x,c,y=0,n,m,l,w,sum=0,sum2=0;
    string t,ans;
    bool f=true;
    cin >> n;
    VII alpha(n, vector<int>(26));
    VS s(n);
    rep(i,n){
        cin >> s[i];
        rep(j,s[i].size()){
            alpha[i][s[i][j]-'a']++;
        }
    }
    rep(j,26){
        rep(i,n){
            if(Min > alpha[i][j]){
                Min = alpha[i][j];
            }
        }
        if(Min > 0){
            while(Min!=0){
                ans += j+'a';
                Min--;
            }
        }
        Min = 1e9+1;
    }
    cout << ans << endl;
    return 0;
}