#include <bits/stdc++.h>
using namespace std;

const int INF = 99999999;

int main(){
  int N, M;
  vector<int> a(30), b(30);

  cin >> N >> M;
  for(int i=0; i<M; i++) cin >> a[i] >> b[i];

  vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8};

  int cnt = 0;
  do{
    vector<bool> pass(8, false);
    for(int i=0; i<N-1; i++){
      for(int j=0; j<M; j++){
        if (a[j] == A[i] && b[j] == A[i+1]) pass[i] = true;
        if (b[j] == A[i] && a[j] == A[i+1]) pass[i] = true;
      }
    }

    bool flag = true;
    for(int i=0; i<N-1; i++) flag = flag && pass[i];
    if (flag) cnt++;
  }while(next_permutation(A.begin()+1, A.begin()+N));

  cout << cnt << endl;
}