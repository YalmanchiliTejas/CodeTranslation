#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
 
typedef long long ll;
typedef long double ld;
 
#define REP(i,a,n) for(int (i)=(a); (i)<(int)(n); (i)++)
#define rep(i,n) REP(i,0,n)
#define vec vector 

const ll large_P = 1e9 + 7;


int main(){
  int N, M;
  cin >> N >> M;
  
  if(N == M){
    cout << "Yes";
  }else{
    cout << "No";
  }
  
}