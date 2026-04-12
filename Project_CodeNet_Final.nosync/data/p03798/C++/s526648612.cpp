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

const int QUA = 1e9 + 7;

int n;
vector<bool> A;
string s;

void prnt(){
  for(int i = 0; i < n;i++){
    printf("%c", (A[i] ? 'S' : 'W'));
  }
  puts("");
}

bool prgct(bool a, bool b){
  A[0] = a; A[1] = b;
  for(int i = 1; i < n - 1;i++){
    A[i + 1] = ((s[i] == 'o') == A[i]) == A[i - 1];
  }
  bool tmp = ((s[n - 1] == 'o') == A[n-1]) == A[n - 2];
  if(A[0] == tmp){
    if(A[1] == (((s[0] == 'o') == A[0]) == A[n - 1])){
      prnt();
      return false;
    }
  }
  return true;
}

int main(){

  cin >> n >> s;
  A.resize(n);

  bool flag = true;
  if(flag){
    flag = prgct(true, true);
  }
  if(flag){
    flag = prgct(true, false);
  }
  if(flag){
    flag = prgct(false, true);
  }
  if(flag){
    flag = prgct(false, false);
  }
  if(flag){
    puts("-1");
  }
  return 0;
}