#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
  long long N;
  long long X,M,A;
  std::cin>>N>>X>>M;
  A = X;
  long long count = X;
  std::vector<long long> vec;
  vec.push_back(X);
  std::vector<long long>::iterator itr;
  long long a = 2;
  long long index = 0;
  for(; a <= N; a++)
  {
    X = (X * X) % M;
    count += X;
    itr = std::find(vec.begin(), vec.end(), X);
    
    if(itr != vec.end())
    {
      index = std::distance(vec.begin(), itr);
      vec.push_back(X);
      break;
    }
    vec.push_back(X);
  }
  long long XXX = A;
  long long counttt = A;
  for(long long c = 2; c <= index + 1; c++)
  {
    XXX = (XXX * XXX) % M;
    counttt += XXX;
  }
  long long b = (N-a)%(a-index-1);
  count = count + (count - counttt) * ((N-a-b)/(a-index-1));
  for(long long c = 1;c <= b; c++)
  {
    X = (X*X)%M;
    count += X;
  }
  std::cout<<count;
}
