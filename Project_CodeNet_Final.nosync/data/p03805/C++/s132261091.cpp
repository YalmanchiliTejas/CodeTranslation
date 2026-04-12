#include<bits/stdc++.h>
using namespace std;
//next_permutationの実装
int main(){
  int N,M;
  cin >> N >> M;
  vector<int> a(M);
  vector<int> b(M);
  //adjacent_list
  vector<vector<int>> al(N+1);
  //入力
  for(int i = 0; i < M; i++){
    cin >> a.at(i) >> b.at(i);
    //隣接リストの作成
    al.at(a.at(i)).push_back(b.at(i));
    al.at(b.at(i)).push_back(a.at(i));
  }

  //頂点を代入していく。(sort済み)
  vector<int> v = {1};
  for(int i = 2; i <= N; i++){
    v.push_back(i);
  }

  // for(int i = 0; i < N; i++){
  //   cout << v.at(i) <<endl;
  // }

  int ans = 0;
  //先頭が1の順列を全て調べあげる。
  while(v.at(0)==1){
    //vが頂点の列
    int counter = 0;
    //N-1本の辺が実際に存在するかを確かめる。
    while(counter < N-1){
      //v.at(counter+1)がal.at(v.at(counter)に含まれているかを確認する。)
      vector<int> ajl = al.at(v.at(counter));
      auto itr = find(ajl.begin(),ajl.end(),v.at(counter+1));
      //辺が含まれていなければ次の順列へ
      if(itr==ajl.end()) break;
      counter++;
    }
    if(counter==N-1)ans++;
    // for(auto i:v)cout<<i;
    // cout<<endl;
    next_permutation(v.begin(),v.end());
  }
  cout<<ans<<endl;
}
