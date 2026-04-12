#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4

int main(){
  int N,M; cin >> N >> M;
  int P[N+1][N+1] = {};
  int a, b;
  rep(i,M){
    cin >> a >> b;
    P[a][b] = 1;
    P[b][a] = 1;
  }
  vector<int> A(N);
  rep(i,N) A[i] = i + 1;

  int cnt = 0;
  do{
    if (A[0]!=1) continue;

    bool possible = true;
    for (int i=0;i<N-1;i++) {
      if (P[A[i]][A[i+1]]==0) possible = false; 
    }
    
    if (possible) cnt++;
  }while(next_permutation(all(A)));

  cout << cnt << endl;

  return 0;
}