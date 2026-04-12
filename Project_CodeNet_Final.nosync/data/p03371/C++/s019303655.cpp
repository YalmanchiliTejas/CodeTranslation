#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

const ll modseed = pow(10,9) + 7;

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  ll ans = 0;
  int ar=0;
  int br=0;
  int cr=0;
  for(int c=0;c<=100000;c++){
    int a = max(0, X-c);
    int b = max(0, Y-c);
    ll result = c * 2 * C + a*A+b*B;
    if(ans==0){
      ans = result;
    }else{
      ans = min(ans, result);
    }
  }
  printl(ans);
}
