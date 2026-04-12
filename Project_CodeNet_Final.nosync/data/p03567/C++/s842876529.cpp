#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) FOR(i,0,b)
#define INF mugen
#define dump(x) cerr<<#x<<"="<<x<<endl
#define all(a) (a).begin(),(a).end()
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
template <class T> void chmin(T & a, T const & b) { if (b < a) a = b; }

using ll = long long;
const ll mod = LLONG_MAX;

int main(){
 string s;
 cin>>s;
 for(int i=0;i<s.size()-1;i++){
   if(s[i]=='A'&&s[i+1]=='C'){
     cout<<"Yes"<<endl;
     return 0;
   }
 }
 cout<<"No"<<endl;


}
