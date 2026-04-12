#include <bits/stdc++.h>
using namespace std;
#define int long long
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}
 
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    for (int i = 0; i < v.size(); ++i)
      os << v[i] << " ";
    os << '\n';
  }
  return os;
}
signed main() {
    int n, x, m;
    cin >> n >> x >> m;
    vector<int> vec;
    vec.push_back(x);
    set<int> s;
    int value = (x*x)%m;
    s.insert(x);
    int i;
    while(s.find(value) == s.end())
    {
        vec.push_back(value);
        s.insert(value);
        value = (value*value)%m;
    }
    int idx = -1;
    for(i=0;i<vec.size();i++)
        if(vec[i] == value)
            break;
    idx = i;
    int cyc = vec.size() - idx;
    if(n < vec.size())
    {
        int sum = 0;
        for(i=0;i<n;i++)
            sum+=vec[i];
        cout << sum;
    }
    else
    {
       // cout << vec.size() << " " << value;
        int sum = 0;
        for(i=0;i<idx;i++)
            sum+=vec[i];
        //cout << sum << '\n';
        int tot = 0;
        for(i=idx;i<vec.size();i++)
            tot+=vec[i];
        n = n - idx;
        sum = sum + tot*(n/cyc);
        n = n%cyc;
        for(i = idx; i < idx + n;i++)
            sum+=vec[i];
        cout << sum;
    }
   // cout << vec.size() << " " << value << '\n';
}