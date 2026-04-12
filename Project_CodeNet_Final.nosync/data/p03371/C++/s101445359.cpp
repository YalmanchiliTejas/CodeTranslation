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

ll Max=-1,Min=1e9+1;
       
int main(){
    ll a,b,c,x=0,y=0,n,m,k,w,sum=0,ans=0;
    string s,t;
    bool f=true;
    cin >> a >> b >> c >> x >> y;
    if(x>y){
        m=y;w=x;k=x-y;
    }
    else{
        m=x;w=y;k=y-x;
    }

    if(2*c>a+b){
        ans += a*x + b*y;
    }
    else{
        ans += m*c*2;
        if(x>y){
            if(2*c>a){ 
                ans += a*k;
            }   
            else{
                ans += k*2*c;
            }
        }
        else{
            if(2*c>b){ 
                ans += b*k;
            }   
            else{
                ans += k*2*c;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

