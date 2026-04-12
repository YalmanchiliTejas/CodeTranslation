#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

int main () {
  cin.tie(0);
  cout << fixed << setprecision(10);

  map<char, int> mp;
  for(int i=2;i<=9;++i) {
    mp[(char)i + '0'] = i;
  }
  mp['T'] = 10;
  mp['J'] = 11;
  mp['Q'] = 12;
  mp['K'] = 13;
  mp['A'] = 14;

  while(1) {
    char t; cin >> t;
    if(t == '#') break;
    vector<vector<pair<int, char>>> a(4);
    for(int i=0;i<4;++i) {
      for(int j=0;j<13;++j) {
        string s; cin >> s;
        a[i].push_back(make_pair(mp[s[0]], s[1]));
      }
    }

    int trns = 0, trew = 0;
    int lead = 0;
    for(int i=0;i<13;++i) {
      char suit = a[lead][i].second;

      bool tr = suit == t;
      int trma = (tr ? a[lead][i].first : 0);
      int ma = a[lead][i].first;
      int argma = lead;

      for(int j=0;j<4;++j) {
        if(j == lead) continue;
        if(a[j][i].second == t && a[j][i].first > trma) {
          tr = true;
          trma = a[j][i].first;
          argma = j;
        } else if(!tr && a[j][i].second == suit && a[j][i].first > ma) {
          ma = a[j][i].first;
          argma = j;
        }
      }

      lead = argma;
      if(argma == 0 || argma == 2) trns++;
      else trew++;
    }

    if(trns > trew) {
      cout << "NS" << " " << trns - 6 << endl;
    } else {
      cout << "EW" << " " << trew - 6 << endl;
    }

  }
}

