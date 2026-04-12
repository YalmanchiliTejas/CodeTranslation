#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;  cin >> N;
  int maxheight = 0;
  int ans = 0;
  for(int i=0;i<N;i++){
    int H;
    cin >> H;
    if(maxheight <= H){
      ans ++;
      maxheight = H;
    }
  }
  cout << ans << endl;
}
