#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define reptr(i,n) for(int (i)=(n);(i)>=0;--(i))
#define All(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> h(N);
  rep(i,N){
    cin >> h[i];
  }
  int max = h[0];
  int cnt = 1;
  for(int i=1;i<N;i++){
    if(max<=h[i]){
      max = h[i];
      cnt++;
    }
  }
  cout << cnt << endl;
}