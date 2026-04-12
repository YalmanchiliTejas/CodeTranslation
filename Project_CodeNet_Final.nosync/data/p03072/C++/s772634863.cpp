#include<iostream>
using namespace std;
int main()
{
  int N;
  cin >> N;
  
  int H[N];
  for(int i=0; i<N; i++){
    cin >> H[i];
  }
  
  int count;
  count = 1; // added first mountain
  
  int max_H;
  max_H = H[0];
  
  for(int i=1; i<N; i++){
    if(H[i] >= max_H){
      count += 1;
      max_H = H[i];
    }
  }
  
  cout << count << endl;
  
}