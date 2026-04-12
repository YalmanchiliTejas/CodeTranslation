#include <iostream>

using namespace std;

int main()
{
  int N;
  cin >> N;
  int m=0;
  int ans=0;
  for( int i=0;i<N;i++ )
    {
      int h;
      cin >> h;
      if( h>=m )
	{
	  ans++;
	  m = h;
	}
    }
  cout << ans << endl;
  return 0;
}
