#include <iostream>

using namespace std;

int N, M;

int main()
{
  	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
  
  cin >> N >> M;
  
  if (N == M)
    cout << "Yes";
  else
    cout << "No";
  
  return 0;
}