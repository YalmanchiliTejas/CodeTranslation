#include <bits/stdc++.h>
using namespace std;

#define COUNTOF(a) (sizeof(a)/sizeof(a[0]))
#define SP << " " <<
typedef long long ll;
template<class T> istream& operator >> (istream& s, vector<T>& v) {
  for (T& x: v) s >> v;
  return s;
}


int main(void)
{
    cin.tie(0); ios::sync_with_stdio(false);

    int r, g, b; cin >> r >> g >> b;
    cout << (((g*10+b)%4)?"NO":"YES") << endl;
}
