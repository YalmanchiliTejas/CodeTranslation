#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
 
long long Length(int l){
  if(l == 0) return 1;

  long long x = Length(l-1);
  return 3 + 2*x;
}

long long P(int l){
  if(l == 0) return 1;

  return 1 + 2*P(l-1);
}
int main(){
  long long n, x, ans=0;

  cin >> n >> x;

  long long l = n; 
  while(x > 0 && l > 0){
    if(x >= (Length(l) + 1) / 2){
      x -= (Length(l) + 1) / 2;
      ans += P(l-1) + 1;
    }else{
      --x;
    }
    --l;

    if(l == 0 && x > 0) ++ans;
  }

  cout << ans << endl;
}
