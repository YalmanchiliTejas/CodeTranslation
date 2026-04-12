#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0 ; i<(n) ; i++)
#define repr(i,n) for(int i=(n) ; i>=0 ; i--)
#define FOR(i,m,n) for(int i=(m) ; i<(n) ; i++)
#define FORR(i,m,n) for(int i=(m) ; i>=(n) ; i--)

#define All(x) (x).begin(),(x).end()

typedef long long ll;
typedef unsigned long long ull;

const int INF = 1e9;

int main(){
   string s;cin >> s;
   for(int i=0;i<s.size()-1;i++){
      if(s[i] == 'A' && s[i+1] == 'C'){
         cout << "Yes";
         return 0;
      }
   }
   cout << "No";
   return 0;
}