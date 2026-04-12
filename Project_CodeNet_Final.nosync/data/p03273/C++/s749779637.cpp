#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);


ll gcd(ll a, ll b){  if(b==0){  return a; }   return gcd(b , a%b); }


vector<int> row,col;

int row_check(int num ){

  for(int i=0;i<row.size();i++){
    if(row[i] == num){
      return 0;
    }
  }
return 1;
}

int col_check(int num ){

  for(int i=0;i<col.size();i++){
    if(col[i] == num){
      return 0;
    }
  }
return 1;
}



int main() {

 
int n,m;
cin>>n>>m;

char a[n][m];
REP(i,n){
  REP(j,m){
    cin>>a[i][j];
  }
}


// REP(i,n) {
//   REP(j,m) {
//     cout<<a[i][j];
//   }
//   cout<<"\n";
// }

REP(i,n) {
  int cnt = 0;


  REP(j,m){
    if(a[i][j] == '.'){
      cnt++;
    }
  }
  if(cnt == m){
    row.push_back(i);
  }
}
// cout<<"\n\n";

REP(i,m){
  int cnt = 0;
  REP(j,n){
     if(a[j][i] == '.')
     { cnt++;}
    // cout<<a[j][i];
    
  }
 
 if(cnt == n){
   col.push_back(i);
 }

  // cout<<"\n";
}



// for(int i=0;i<row.size();i++){
//   cout<<row[i]<<" ";
// }
// cout<<"\n";

// for(int i=0;i<col.size();i++){
//   cout<<col[i]<<" ";
// }


for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){

    if( row_check(i) && col_check(j)){
      cout<<a[i][j];
    }
  }
  cout<<"\n";
}





  
  return 0;
}
