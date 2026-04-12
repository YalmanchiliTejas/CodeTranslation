#include <iostream>
#include <vector>
//#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
/*
class Hoge{
  public:
    int m_hoge;
  Shop(int hoge){
    m_hoge = hoge;
  }
  bool operator<(const Hoge &another) const
  {
    return hoge < another.hoge;
  };
};
*/
int main(){
  int N,ans = 0,max;
  vector<int> H;
  cin >> N;
  for(int i=0;i<N;i++){
    int temp;
    cin >> temp;
    H.push_back(temp);
  }
  max = H[0];
  for(int i=0;i<N;i++){
    if(H[i]>=max){
      max = H[i];
      ans++;
    }
  }
  cout << ans << endl;
}