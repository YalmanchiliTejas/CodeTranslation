#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
using vi = vector<int>;
using vll = vector<long long int>;
using vii = vector<vi>;
using pii = pair<int, int>;

#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i, a, b) for(int (i) = a; (i) < (b);(i)++)
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a > b) ? b : a)

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const int MOD = 1e9 + 7;



int main(){
  int n; cin >> n;
  vi A(n); REP(i, n) cin >> A.at(i);
  sort(A.begin(), A.end());
  int s = A.size();
  int hd = A.front(), tl = A.back();
  ll ans = tl - hd;
  for(int i = 1; i < s/2;i++){
    if(i % 2 == 1){
      ans += tl - A[i];
      tl = A[i];
      ans += A[s - i - 1] - hd;
      hd = A[s - i - 1];
    }
    else{
      ans += hd - A[i];
      hd = A[i];
      ans += A[s - i - 1] - tl;
      tl = A[s - i - 1];
    }
  }
  if(s % 2 == 1) ans += MAX( abs(A[s/2] - hd), abs(A[s/2] - tl));
  cout << ans << endl;
  return 0;
}