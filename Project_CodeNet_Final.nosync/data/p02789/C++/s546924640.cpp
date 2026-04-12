#include <bits/stdc++.h>
using namespace std;

typedef struct date{
  long long min;
  long long max;
}date;

int cmp( const void *p, const void *q ) {
    return  ((date*)q)->min - ((date*)p)->min ;
}

int main() {
  int n , m;
  cin >> n >> m;

  if(n == m)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

}
