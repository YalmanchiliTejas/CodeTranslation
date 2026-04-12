#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

//入力のX
long long X;

//N=iでの層の総数
long long sum[51];

//N=iでのパティの総数
long long psum[51];

//
long long calc(int level){
  long long half = (sum[level]+1)/2;

  //レベル0バーガー
  if(level == 0){
    //1層食べられる
    if(X>0)
      return 1;
    //1層も食べられない
    else
      return 0;
  }

  //食べる層が総数の半分未満
  if(X < half ){
    //最下層のバンを除いてlevel-1バーガーへ再帰
    X--;
    return calc(level-1);
  }
  //食べる層が総数の半分
  else if(X == half){
    //level-1バーガーを全て食べて，中心のペティを食べる
    return psum[level-1] + 1;
  }
  //食べる層が総数の半分より多い
  else{
    //食べるバーガーの補正
    //下側のlebel-1バーガーを取り除き，上下端のバンと中央のペティを取り除く
    X = X - sum[level-1] - 3 + 1;
    //level-1バーガーで再帰し，下側のlevel-1バーガーのペティ，中央のペティを足す
    return calc(level-1) + psum[level-1] + 1;
  }
  
  return 1;
}


int main(void){
  int N;
  cin >> N >> X;
  //入力終わり  

  //初期化
  sum[0] = 1;
  psum[0] = 1;

  //レベルiの層の総数とパティの総数を計算
  rep(i, N){
    sum[i+1]  = 2*sum[i] + 3;
    psum[i+1] = 2*psum[i]+1;
  }

  //解答
  cout << calc(N) << endl;
  
  return 0;
}
