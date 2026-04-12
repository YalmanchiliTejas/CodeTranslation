#include "bits/stdc++.h"
using namespace std;
#define INF 1000000000
#define rep(i, n) for(int i = 0; i < n; i++)
#define ALL(x) (x).begin(), (x).end()  //昇順
#define RALL(x) (x).rbegin(), (x).rend() // 降順
const long long mod = 1e9+7;
typedef priority_queue<int> PQ;
typedef vector<long long> Vl;
typedef vector<int> VI;  // VI a(n);
typedef vector<string> VS;  
typedef vector<char> VC; 
typedef vector<VS> VSS;
typedef vector<VC> VCC;    
typedef vector<VI> VVI;   // VVI a(n,vector<int>(m)) n * m 
typedef vector<Vl> VVl;
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

int main(){
    int c,d=0,x=0,n,r=0,g,m,p,h,k,w,max=-10000000,min=1000000000,ans=0,sum=0;
    string s;
    bool f=true;
    cin >> h >> w;
    VCC a(h,vector<char>(w));

    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    
    while(x<=h-1){
        sum = 0;
        rep(j,w){
            if(a[d][j]=='.')
                sum++;
        }
        if(sum == w){
            g++;
            for(int k=d; k<h-1;k++){
                rep(j,w){
                    a[k][j] = a[k+1][j];
                }
            }
        }
        else{
            d++;
        }
        x++;
    } 

    x=0;
    d=0;
    
    while(x<=w-1){
        sum = 0;
        rep(i,h-g){
            if(a[i][d]=='.')
                sum++;
        }
        if(sum == h-g){
            r++;
            for(int k=d; k<w-1;k++){
                rep(i,h-g){
                    a[i][k] = a[i][k+1];
                }
            }
        }
        else{
            d++;
        }
        x++;
    }

    rep(i,h-g){
        rep(j,w-r){
            if(j==w-1-r)
                cout << a[i][j] <<endl;
            else
                cout << a[i][j];
        }
    }

    return 0;
}