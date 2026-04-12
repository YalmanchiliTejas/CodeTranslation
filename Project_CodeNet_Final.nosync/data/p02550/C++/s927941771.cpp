#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  long long N, X, M;
  cin >> N >> X >> M;
  set<long long> amari;
  long long ans = 0;
  ans += X;
  amari.insert(X);
  vector<long long> kotae(1);
  vector<long long> x;
  x.push_back(X);
  kotae.push_back(X);
  int i = 1;
  for(i; i <= N; i++){  
    X = X * X % M;
    if(amari.count(X)){  
      break; 
    }
    amari.insert(X);
    ans += X;
    kotae.push_back(ans);
    x.push_back(X);
  }
  int j = 0;
  long long tmp2 = 0;
  for(j = 0; j < N; j++){  
    if(x[j] == X){  
      break; 
    } 
    tmp2 += x[j];
  }
  long long tmp = 0;
  for(int k = j; k < x.size(); k++){  
    tmp += x[k];
  }
  int kukan = i - j;
  int saisyo = j;
  long long a = 0;
  for(int t = 0; t < (N - saisyo) % kukan; t++){  
    a += x[j + t];
  }
  cout << tmp2 + (N - saisyo) / kukan * tmp + a <<endl;
}
