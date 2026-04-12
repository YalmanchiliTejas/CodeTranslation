// V solo
#include <bits/stdc++.h>

#define forn(i, a, b) for (int i = a; i <= b; ++i)
#define forr(i, a, b) for (int i = a; i >= b; --i)

using namespace std;

const int N = (int)2e5 + 7;
const long long INF = 1e15 + 7;

typedef long long ll;
typedef long double ld;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;


int n;
deque < int > dq;
int main (){
  scanf ("%d", &n);
  forn (i, 1, n){
    int x;
    scanf ("%d", &x);
    if (i & 1) dq.push_front(x);
    else dq.push_back(x);
  }
  if (n % 2 == 0){
    while (!dq.empty()){
      printf ("%d ", dq.back());
      dq.pop_back();
    }
  } else {
    while (!dq.empty()){
      printf ("%d ", dq.front());
      dq.pop_front();
    }
  }
  return 0;
}
