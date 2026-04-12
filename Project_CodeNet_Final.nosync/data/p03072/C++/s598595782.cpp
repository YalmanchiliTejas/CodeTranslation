#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0;i < (int)(n);i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n);i++)
#define ALL(vec)  (vec).begin(),(vec).end()
#define lli long long int
#define pi 3.1415926535897932384626433832795
#define MAX_INF 9223372036854775807
#define MIN_INF 9223372036854775807+1
#define sosuu 1000000007

int main(){
  int N;
  cin >> N;
  int ans=1;
  int a,b;
  int judge;
  rep(i,N){
  if(i==0){
  cin >> a;
    continue;
  }
    cin>>b;
    judge=max(a,judge);
    if(judge<=b)
      ans++;
    a=b;
  }
  cout << ans << endl;
}
