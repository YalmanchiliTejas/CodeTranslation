#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define reptr(i,n) for(int (i)=(n);(i)>=0;--(i))
#define All(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
const ll KEY = 998244353;
using namespace std;

int main(){
  int N,K;
  string s;
  cin >> N >> s >> K;
  char key = s[K-1];
  rep(i,N){
    if(s[i]!=key) s[i] = '*';
  }
  cout << s << endl;
}
