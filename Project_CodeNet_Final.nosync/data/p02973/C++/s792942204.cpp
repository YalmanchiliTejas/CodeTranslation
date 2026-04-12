#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, res;
vector<ll> A(100010);
vector<int> color;  //color[i] := 各色についてi+1番目に最右値の大きいもの

/* A内のval未満の最大値が格納されている添え字を返す*/
/*color内の値が降順整列であることに注意*/
int tree_search(int l, int r, int val){
	if(l == r) return l;

	int c = (r - l) / 2 + l;  //lとcの間
	if(val <= color[c]) return tree_search(c+1, r, val);  //color[c]は条件を満たさない
        else if(val > color[c]) return tree_search(l, c, val);  //color[c]も条件を満たす

}



ll color_n(int num){  //範囲設定num
 ll cn = 0, j;  //cnは(色の数-1)
 color.push_back(A[0]);  //color最右値を決定

 for(ll i = 1; i < num; i++){
  if(A[i] > color[0]) color[0] = A[i]; //最も最右値の高い色を使用
  else if(A[i] <= color[0] && A[i] > color[cn]){ 
   j = tree_search(0, cn, A[i]);
   color[j] = A[i]; 
  }  //条件を満たす最大色値を使用
  else { color.push_back(A[i]); cn += 1; } //新色追加
  
 }

 return (cn+1);
}



int main(){
 cin >> N;
 for(int i = 0; i < N; i++) cin >> A[i];

 res = color_n(N);  //使う色数
 //for(ll i = 0; i < color.size(); i++) cout << color[i] << endl;
 cout << res << endl;
 return 0;
}