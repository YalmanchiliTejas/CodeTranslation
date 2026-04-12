#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int result =2147483647;
  for(int i = 0; i < 200001; i += 2){
    int tmp = C * i + A * (i/2< X ? X-i/2 : 0) + B * (i/2<Y ? Y-i/2 : 0);
    if(tmp < result){
      result = tmp;
    }
  }
  cout << result << endl;
}
