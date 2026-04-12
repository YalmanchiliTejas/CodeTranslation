#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
typedef pair<ll,ll> P;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
set<char> s;
s.insert('y');s.insert('h');s.insert('n');s.insert('u');s.insert('j');s.insert('m');s.insert('i');s.insert('k');s.insert('o');s.insert('l');s.insert('p');
while(1){
    string t;
    cin>>t;
    if(t[0]=='#')return 0;
    int now=(s.find(t[0])!=s.end());
    int ans=0;
    for(int i=1;i<t.size();i++){
             if(now!=(s.find(t[i])!=s.end())){
                 ans++;
                 now^=1;
             }
    }  
    cout<<ans<<endl;
  }
}
