#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,K;
  	string S;
  	cin >> N;
    cin >> S;
    cin >> K;
  	string o;
    for(int i = 0; i < N; i++)
    {
      if(S[K-1] != S[i])
      {
        o += '*';
      }
      else
      {
        o += S[i];
      }
    }
  	cout << o << endl;
	
  return 0;
}