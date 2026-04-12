#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
bool debug = false;
int tmp_iA,tmp_iB;

int main() {
  int N; cin >> N; // 頂点の数（２～８）
  int M; cin >> M; // 辺の数（０～N(N-1)/2)
  // 辺の有無を２次元配列（裏表）に為、頂点全列挙順列に対し、最後まで辿れるか、判定する。
  vector<vector<bool>> Hen(8,vector<bool>(8,false));  // 辺有無２次元真偽配列
  int a,b;
  rep(i,M){
    cin >> a >> b;
    Hen.at(a-1).at(b-1) = Hen.at(b-1).at(a-1) = true;   // 繋がってるフラグを裏表で持つ。頂点番号は０からＮ－１
  }
  int Ans = 0; // 最後まで行けるパス数
  vector<int> Choten;
  rep(i,N){Choten.push_back(i);}  // 全頂点の数値配列。ソート済み。

  do{   // 頂点全列挙順列に対する処理
    if(Choten.at(0)!=0){continue;}  // 開始点が０で無い場合、除外

    bool Through = true;
    rep(i,N-1){
//      cout << "i:" << i << " Hen:"  << Hen.at(Choten.at(i)).at(Choten.at(i+1)) << endl;
      if(!Hen.at(Choten.at(i)).at(Choten.at(i+1))){
        Through = false;
        break;
      }
    }
    if ( Through ) { Ans+=1; }
  } while(next_permutation(Choten.begin(),Choten.end()));
  cout << Ans << endl;
}