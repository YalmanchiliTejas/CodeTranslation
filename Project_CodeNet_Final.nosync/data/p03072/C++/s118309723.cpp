#include<iostream>/*入出力関連ヘッダファイル*/
using namespace std;/*標準名前空間を利用する。cinやcoutはこれによって利用可能になる*/

int N;
int H[105];
int count;

int main(void) {
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> H[i];
  }
  int max=0;
  for(int i=0; i<N; i++){
    if(H[i]>=max){
      max=H[i];
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
