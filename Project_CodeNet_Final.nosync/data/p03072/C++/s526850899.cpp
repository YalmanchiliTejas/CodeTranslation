#include<iostream>
using namespace std;
int main()
{
  int N;
  cin >> N;
  
  int H[N];
  for (int i = 0; i < N; i++){
    cin >> H[i];
  }
  
  int h = 0;
  int num = 0;
  for(int i = 0; i < N; i++){
    if(h <= H[i])
    {
      h = H[i];
      num++;
    }
  }
  cout << num << endl;
  return 0;
      
}