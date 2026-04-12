#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  
  deque<ll> que;
  for(int i = 0; i < n; i++)
  {
	int v;
	cin >> v;
	if(i % 2 == 0) {
	  que.push_front(v);
	} else {
	  que.push_back(v);
	}
  }

  if(n % 2 == 1) {
	for(int i = 0; i < n; i++) {
	  cout << (i > 0 ? " " : "") << que[i];
	}
  } else {
	for(int i = n - 1; i >= 0; i--) {
	  cout << (i < n - 1 ? " " : "") << que[i];
	}
  }
  cout << endl;
  
  return 0;
}
