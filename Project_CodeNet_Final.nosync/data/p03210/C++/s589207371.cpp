#include<bits/stdc++.h>
using namespace std;
// g++ Main.cpp -std=gnu++1y -O2 -I/opt/boost/gcc/include -o main && ./main

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<vl>;
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
  if(n == 7 || n == 5 || n == 3) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}