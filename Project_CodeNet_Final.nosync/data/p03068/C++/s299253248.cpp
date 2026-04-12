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
   int n,k;
   string s;
   cin >> n >> s >> k;
   char target = s[k-1];
   rep(i,n){
      if(target != s[i])s[i] = '*';
   }
   cout << s;
   return 0;
}