#include "bits/stdc++.h"
using namespace std;
#define INF 1e9
#define rep(i, n) for(int i=0;i<n;i++)
#define ALL(x) (x).begin(), (x).end()  //昇順
#define RALL(x) (x).rbegin(), (x).rend() // 降順
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
const long long mod = 1e9+7;
typedef priority_queue<int> PQ;
typedef vector<long long> VL;
typedef vector<bool> VB;
typedef vector<int> VI;  // VI a(n);
typedef vector<double> VD;  
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
template <class T, class U>  // chmax(max, a);
bool chmax(T &a, U b){
    if (a < b){ a = b;return 1;}
    return 0;
}
template <class T, class U> //chmin(min,a)
bool chmin(T &a, U b){
    if (a > b){ a = b; return 1;}
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
template<typename T>
T gcd(T a, T b){
	return b != 0 ? gcd(b, a % b) : a;
}    
template<typename T>
T lcm(T a, T b){
    return a/gcd(a,b)*b;
}    
        
int main(){
    ll x,y,z,n,m=0,k,h,w,sum=0,ans=0,Max=-1e9,count=0,Min=1e9+1;
    string s,t,u1,u2;
    bool ok=true;
    cin >> h >> w;
    VCC o(h+2, vector<char> (w+2));
    rep(i,h+2){
        rep(j,w+2){
            o[i][j]='.';
        }
    }
    for(int i=1; i<h+1;i++){
        for(int j=1; j<w+1; j++){
            cin >> o[i][j];
        }
    }
    x=0; y=0;
    for(int i=1; i<h+1;i++){
        for(int j=1; j<w+1; j++){
            if(o[i][j]=='#'){
                if(i>=y && j>=x){
                    x = j; y = i;
                    continue;
                }
                else{
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Possible" << endl;
    return 0;
}