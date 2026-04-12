#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

int main(){
ll N, Ans = 0;cin >> N;
priority_queue<ll> P;
priority_queue<ll> Q;

rep(i, 0, N){

  ll p;cin >> p;

  P.push(p);Q.push(p);

}

if(N%2 == 1){

  ll A = 0, B = 0;

  rep(i, 1, N + 1){

    if(i <= N/2){

      A += 2*P.top();P.pop();continue;

    }

    if(N/2 < i && i <= N/2 + 2){

      A -= P.top();P.pop();continue;

    }

    else{

      A -= 2*P.top();P.pop();continue;

    }

  }

  rep(i, 1, N + 1){

    if(i <= N/2 - 1){

      B += 2*Q.top();Q.pop();continue;

    }

    if(N/2 - 1 < i && i <= N/2 + 1){

      B += Q.top();Q.pop();continue;

    }

    else{

      B -= 2*Q.top();Q.pop();continue;

    }

  }

Ans = max(A, B);

}

if(N%2 == 0){

  rep(i, 1, N + 1){

    if(i <= N/2 - 1){

      Ans += 2*P.top();P.pop();continue;

    }

    if(N/2 == i ){

      Ans += P.top();P.pop();continue;

    }

    if(N/2 + 1 == i ){

      Ans -= P.top();P.pop();continue;

    }

    else{

      Ans -= 2*P.top();P.pop();continue;

    }

  }

}

cout << Ans;

}