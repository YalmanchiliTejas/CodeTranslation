#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
  // 2~nの順列を生成すればよい.(始点が1で固定なので)

  int N,M; cin >> N >> M;

  vector<int> v(N);
  for(int i = 0;i < N;i++){
    v[i] = i + 1;
  }

  vector<pair<int,int>> e(M);
  for(int i = 0;i < M;i++){
    int a,b; cin >> a >> b;
    e[i] = make_pair(a,b);
  }


  int ans = 0;


  do{
    bool flag = true;

    for(int i = 0;i < N - 1;i++){
      int a = min(v[i],v[i+1]);
      int b = max(v[i],v[i+1]);

      if(find(e.begin(),e.end(),make_pair(a,b)) == e.end()){
        flag = false;
        break;
      }
    }

    if(flag)ans++;

  }while(next_permutation(v.begin()+1,v.end()));


  cout << ans << endl;



}
