#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

class St{
public:
  string y, m, d;
  int s, t, u;

  St(){}
  St(string _y, string _m, string _d): y(_y), m(_m), d(_d){
    s = atoi(_y.c_str());
    t = atoi(_m.c_str());
    u = atoi(_d.c_str());
  }
};

bool comp(const St& s1, const St& s2)
{
  if(s1.s == s2.s){
    if(s1.t == s2.t){
      return s1.u < s2.u;
    } else {
      return s1.t < s2.t;
      }
  }
  
  return s1.s < s2.s;
}

int main()
{
  int n;
  string y, m, d;
  St a[101];

  while(cin>>n && n){
    for(int i = 0; i < n; i++){
      cin >> y >> m >> d;
      a[i] = St(y, m, d);
    }
    sort(a, a+n, comp);

    for(int i = 0; i < n; i++){
      cout << a[i].y << " " << a[i].m << " " << a[i].d << endl;
    }
  }

  return 0;
}