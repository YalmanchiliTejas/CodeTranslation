#include<iostream>
#include<iomanip>

using namespace std;

int main(){
  std::cin.tie(nullptr);                  // 標準入出力高速化
  std::ios_base::sync_with_stdio(false);  // SとS++の入出力出力を非同期
  int n,m;
  cin>>n>>m;
  n==m ? cout<<"Yes"<<endl : cout<<"No"<<endl;
}