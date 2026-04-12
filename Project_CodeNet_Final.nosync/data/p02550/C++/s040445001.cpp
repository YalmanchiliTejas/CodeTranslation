#include <iostream>
#include <vector>

int main(){
  long N,X,M;
  std::cin >> N >> X >> M;

  //ループ発見用table
  long table[100000]={};

  //ループ中の値を格納
  std::vector<long> P;

  //ループの発見
  long now=X;
  while(table[now]==0){
    P.push_back(now);
    table[now]=1;
    now=(now*now)%M;
  }

  //ループの始まりと終わりを定義,決定
  long end=P.size();
  long start;
  for(long i=0; i<P.size(); i++){
    if(P[i]==now){
      start=i;
      break;
    }
  }

  //ループ内の合計値
  long loop=0;
  for(long i=start; i<end;i++){
    loop+=P[i];
  }

  //ループの輪のサイズとループする回数の定義
  long loop_size = end-start;
  long loop_num = (N-start)/loop_size;

  //A0~ループ前までの合計
  long result=0;
  for(long i=0; i<start; i++){
    result+=P[i];
  }

  //ループ中の値を加算
  result+=loop_num*loop;

  //ループ終わり~最後までの合計を加算
  for(long i=start; i<start+((N-start)%loop_size);i++){
    result+=P[i];
  }

  //出力
  std::cout << result << std::endl;
  return 0;
}