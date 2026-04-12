#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int N, H, max_H;
  cin >> N;
  int ans=1;
  scanf("%d", &H);
  max_H = H;
  for(int i=0; i<N-1; i++){
    scanf("%d", &H);
    if(max_H <= H){
      ans++;
    }
    max_H = max(max_H, H);
  }
  cout << ans << endl;
}