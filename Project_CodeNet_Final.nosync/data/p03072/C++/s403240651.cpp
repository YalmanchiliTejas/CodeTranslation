#include <iostream>
#include<vector>
using namespace std;
int main(void){
  int N,answer;
  std::cin >> N;
  vector<int> height(N);
  for (int i = 0; i < N; i++)
  {
      cin>>height[i];
  }
  int max=height[0];
  answer=1;
  for (int i = 1; i < N; i++)
  {
      if (max<= height[i])
      {
          max=height[i];
          answer++;
      }
      
  }
  cout<<answer<<endl;
  return 0;
}
