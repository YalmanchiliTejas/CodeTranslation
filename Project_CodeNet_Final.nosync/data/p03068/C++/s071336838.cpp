#include <iostream>
#include <string>

using namespace std;

int main()
{
  int N,K;
  string S;
  cin >> N >> S >> K;

  char c = S[K-1];
  for( int i=0;i<N;i++ )
    if( S[i]!=c )
      cout << '*';
    else
      cout << c;
  cout << endl;
    
}
