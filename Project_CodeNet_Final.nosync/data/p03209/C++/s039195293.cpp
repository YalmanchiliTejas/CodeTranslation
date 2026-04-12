#include <bits/stdc++.h>
using namespace std;
void solveA();
void solveB();
void solveC();
void solveD();
long long func(int,long long);
  
int main() {
  solveD();
}

void solveA(){
  int d;
  cin >> d ;
  string s = "Christmas";

  for(int i = 0; i<25-d; i++){
    s += " EVE";
  }
 
  cout << s <<  endl;
}

void solveB(){
  int n;
  cin >> n ;
  int a[n];

  for(int i = 0; i<n; i++){
    cin >> a[i];
  }
  sort(a,a+n);
  a[n-1] = a[n-1]/2;
    
    int ans = 0;
  for(int i = 0; i<n; i++){
    ans += a[i];
  }
 
  cout << ans <<  endl;
}

void solveC(){
  int n,k;
  cin >> n >> k;
  k--;
  int a[n];

  for(int i = 0; i<n; i++){
    cin >> a[i];
  }
  sort(a,a+n);
    
  int ans = INT_MAX;
  for(int i = 0; i<n-k; i++){
    int dif = a[i+k] - a[i];
    if (dif<ans) ans = dif;
  } 
  cout << ans <<  endl;
}

long long a[55],p[55];

void solveD(){
  int n;
  long long k;
  cin >> n >> k;
  a[0] = 1;
  p[0] = 1;
  
  for(int i = 1; i<=n; i++){
    a[i] = a[i-1]*2 + 3;
    p[i] = p[i-1]*2 + 1;
  }
  long long ans = func(n,k);
  cout << ans <<  endl;
}

long long func(int n, long long k){
  if (n==0) {
    if (k<=0) return 0;
    else return 1;
  }
  else if (k<=a[n-1] + 1) return func(n-1,k-1);
  else return 1 + p[n-1] + func (n-1,k-2-a[n-1]);
}
