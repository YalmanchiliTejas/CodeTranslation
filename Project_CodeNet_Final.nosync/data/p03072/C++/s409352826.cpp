#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;
  int X=0, Y=0;
  
  for(int i=0; i<N; i++){
    int H;
    cin >> H;
    
    if(H<Y)
      continue;
    
    X++;
    Y=H;
  }
  
  cout << X << endl;
}
