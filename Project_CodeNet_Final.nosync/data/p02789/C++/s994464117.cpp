#include<iostream>
using namespace std;

int main()
{
  // 標準入力
  int N,M;
  cin >> N >> M;

  string answer ="No";
  if (N == M)
  {
    answer = "Yes";
  }


  cout << answer;

  return 0;

}