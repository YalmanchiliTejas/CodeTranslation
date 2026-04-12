#include<iostream>/*入出力関連ヘッダファイル*/
#include<string>
using namespace std;/*標準名前空間を利用する。cinやcoutはこれによって利用可能になる*/

int N,K;
string S;

int main(void) {
  cin >> N;
  cin >> S;
  cin >> K;
  for(int i=0; i<N; i++){
    if(S[i]!=S[K-1]){
      S[i]='*';
    }
  }
  
  cout << S << endl;
  return 0;
}