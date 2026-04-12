#include<iostream>
#include<iomanip>

using namespace std;

int main(){
  std::cin.tie(nullptr);                  // 標準入出力高速化
  std::ios_base::sync_with_stdio(false);  // SとS++の入出力出力を非同期
  std::cout << std::fixed << std::setprecision(15);  // 小数を10進数表示

  int n;
  cin>>n;
  cout<<n*800-n/15*200<<endl;
}