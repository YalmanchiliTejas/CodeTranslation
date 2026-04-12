#include<iostream>
#include<vector>
int main()
{
  int N;
  std::cin >> N;
  std::vector<int> H(N);
  int maxh=0,maxn=0;
  for (int i=0;i<N;++i)
  {
    std::cin >> H.at(i);
    if(maxh<=H.at(i))
    {
      maxh=H.at(i);
      maxn++;
    }
  }
  std::cout << maxn <<std::endl;
  return 0;
}