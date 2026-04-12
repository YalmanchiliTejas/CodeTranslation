#include <bits/stdc++.h>
using namespace std;

int calc_next(int a, int b, char s){
  if(s=='o'){
    if(a==b) return 1;
    else return 0;
  }else{
    if(a==b) return 0;
    else return 1;
  }
}
 
int main(){
  int n;
  string s;
  cin >> n;
  cin >> s;
  int a[n+2];
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      bool ok=false;
      a[0] = i;
      a[1] = j;
      for(int i=2; i<n+2; i++){
        a[i]=calc_next(a[i-2],a[(i-1)%n],s[(i-1)%n]);
      }
      if(a[0]==a[n]&&a[1]==a[n+1]) ok = true;
      if(ok){
        for(int k=0; k<n; k++){
          if(a[k]==1) cout << "S";
          else cout << "W";
        }
        cout << endl;
        return 0;
      }
      
    }
  }
  cout << -1 << endl;
  return 0;
}