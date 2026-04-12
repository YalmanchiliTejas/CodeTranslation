#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long ;
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector <int> A(N);
  for( int i=0;i<N;i++ )
    cin >> A[i];

  ll ans = 0;
  sort(A.begin(), A.end());
  vector <int> out;
  out.push_back(A[0]);

  A.erase(A.begin());
  while(!A.empty())
    {
      int c1 = abs(*(out.end()-1)-*(A.end()-1));
      int c2 = abs(out[0]-*(A.end()-1));
      int c3 = abs(out[0]-A[0]);
      int c4 = abs(*(out.end()-1)-A[0]);

      int m = max(c1, max(c2, max(c3, c4)));
      if( m == c1 )
	{
	  out.push_back(*(A.end()-1));
	  A.pop_back();
	  continue;
	}
      else if ( m == c2 )
	{
	  out.insert(out.begin(), *(A.end()-1));
	  A.pop_back();
	  continue;	  
	}
      else if ( m == c3 )
	{
	  out.insert(out.begin(), A[0]);
	  A.erase(A.begin());
	  continue;	  
	}
      else
	{
	  out.push_back(A[0]);
	  A.erase(A.begin());
	  continue;	  
	}
    }

  for( int i=0;i<N-1;i++)
    ans += abs(out[i+1]-out[i]);

  cout << ans << endl;
  return 0;
}  
