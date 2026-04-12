#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> array;
  array.resize(n);
  for( int i = 0;i < n;++i )
    cin >> array[i];

  for( int i = 0;i < n;++i )
  {
    int index = ( n - 1 - i * 2 );
    if( index < 0 ) index = -index - 1;
    cout << array[index] << " ";
  }
}