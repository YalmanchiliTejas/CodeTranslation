#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<int> np(N,0); // next points
  for(int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    np.at(a-1) |= 1<<(b-1);
    np.at(b-1) |= 1<<(a-1);
  }
  int res = 0;
  vector<int> p(N);
  for(int i=0;i<N;i++) p.at(i) = i;
  do{
    if(p.at(0)==0){
      for(int i=1;i<N;i++){
        if(!(np.at(p.at(i-1))>>(p.at(i))&1)){
          break;
        }else if(i==N-1){
          res++;
        }
      }
    }
  }while(next_permutation(p.begin(), p.end()));
  cout << res << endl;
}
