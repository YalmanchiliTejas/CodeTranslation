#include <iostream>
#include <queue>
using namespace std;
int main( void )
{
  ios::sync_with_stdio(false);
  int N, a;
  cin >> N;

  deque<int> q;
  for( int i=0; i<N; i++ ){
    cin >> a;
    if( i % 2 == 0 ){
      q.push_back(a);
    } else {
      q.push_front(a);
    }
  }
  if( N % 2 == 0 ){
    cout << q.front();
    q.pop_front();
    while( !q.empty() ){
      cout << ' ' << q.front();
      q.pop_front();
    }
  } else {
    cout << q.back();
    q.pop_back();
    while( !q.empty() ){
      cout << ' ' << q.back();
      q.pop_back();
    }
  }
  cout << endl;
}
