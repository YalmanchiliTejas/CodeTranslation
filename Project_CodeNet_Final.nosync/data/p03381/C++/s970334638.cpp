#include<iostream>
#include <algorithm>
#include <string>
using namespace std;
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
typedef long long ll;
const int INF = numeric_limits<int>::max();
const int MOD = (1e9 + 7);

int main(){
  int N;
  cin >> N;
  int X[N], Y[N];
  rep(i, N){
    int a;
    cin >> a;
    X[i] = a; Y[i] = a;
  }
  sort(Y, Y+N);
  int med = Y[(N+1)/2];
  rep(i, N){
    if(X[i]<med) cout << med << endl;
    else cout << Y[(N-1)/2] << endl;
  }
      
  
}