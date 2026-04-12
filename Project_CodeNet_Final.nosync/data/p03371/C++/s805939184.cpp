#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define print(s) cout << s << endl; return 0;
#define yes cout << "Yes" << endl; return 0;
#define no cout << "No" << endl; return 0;
#define rep(i,n) for (int i = 0; i <= (n); ++i)
#define rep2(i,n) for (int i = 1; i < (n)+1; ++i)
using ll = long long;

const ll modseed = pow(10,9) + 7;

template <typename T>
vector<T> getValues(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

string S;
ll A,B,C,K,N,X,Y,cnt;

int main(){
  cin >> A >> B >> C >> X >>Y;
  rep(c,max(X,Y)*2){
    int a,b;
    a = max(0LL,X-c/2);
    b = max(0LL,Y-c/2);
    if(c==0){
      cnt = a*A+b*B+c*C;
    }else{
      cnt = min(cnt,a*A+b*B+c*C);
    }
  }
  print(cnt);
}
