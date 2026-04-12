#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
template<class T> inline T gcd(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}else{return 0;}}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}else{return 0;}}

#define MOD 1000000007
typedef long long ll;

int main(){
  int r,g,b;
  cin >> r >> g >> b;
  if((r*100+g*10+b)%4==0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}