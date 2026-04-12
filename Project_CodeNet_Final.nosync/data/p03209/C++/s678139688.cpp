#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  long long int X;
  cin >>N>>X;
  vector<long long int> l(51); // l.at(i) means the number of layers in level i burger
  l.at(0) = (long long int) 1;
  for(int i=1;i<51;i++){
    l.at(i) = l.at(i-1)*2+3;
  }
  vector<long long int> p(51);
  p.at(0) = (long long int) 1;
  for(int i=1;i<51;i++){
    p.at(i) = p.at(i-1)*2+1;
  }
  vector<long long int> a(50,0);
  long long int ans=0;
  for(int i=N-1;i > (-1);i--){
    X--;
    if(X == 0) break;
    if(X > l.at(i)-(long long int)1){
      a.at(i)++;
      X -= l.at(i);
      if(X == 0) break;
      X--;
      ans++;
      if(X == 0) break;
    }
  }
  if(X > 0) ans++;
  for(int i=0;i<N;i++){
    if(a.at(i) == 1){
      ans += p.at(i);
    }
  }
  cout << ans << endl;
}