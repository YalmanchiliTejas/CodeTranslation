#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int N;
vector<pii> A;
int to[200001];

int main(){
  ios_base::sync_with_stdio(false);
  cin >> N;
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A.begin(), A.end());
  for(int i=0; i<N; i++){
    to[A[i].second] = i;
  }

  for(int i=0; i<N; i++){
    if(to[i] < N/2){
      cout << A[N/2].first << "\n";
    }
    else{
      cout << A[N/2 - 1].first << "\n";
    }
  }

  return 0;
}