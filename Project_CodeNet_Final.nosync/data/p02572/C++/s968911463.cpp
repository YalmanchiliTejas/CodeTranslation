#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, Ans = 0, Total = 0;cin >> N;
vector<ll> V(N);
vector<ll> T{0};

rep(i, 0, N){

    cin >> V[i];

    Total += V[i];

    T.push_back(Total);

}

rep(i, 0, N - 1){
  
 ll X = (Total - T[i + 1])%1000000007;

    Ans += V[i]*X;

    Ans %= 1000000007;

}

cout << Ans;

}