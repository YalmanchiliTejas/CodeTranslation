#include<bits/stdc++.h>

using namespace std;

typedef long long int llint;
typedef pair<int, int> pii;
typedef pair<llint, llint> pll;
typedef vector<int> vi;
typedef vector<llint> vli;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define I cin
#define O cout
#define EN endl
#define ln cout<<endl
#define pb(a) push_back(a)
#define x first
#define y second
#define MOD 1000000007

template<typename Tn> Tn gcd(Tn a, Tn b)
{
  return (b ? gcd(b, a % b) : a);
}

template<typename Tn> Tn lcm(Tn a, Tn b)
{
  return a / gcd(a, b) * b;
}

llint cnt = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

map<int, char> m[51];

int main()
{
  int n;
  I >> n;

  string s;
  for(int i = 0; i < n; i++) {
    I >> s;

    for(int j = 0; j < 26; j++) m[i]['a' + j] = 0;
    for(int j = 0; j < s.size(); j++) m[i][s[j]]++;
  }

  string ans = "";
  
  for(int i = 0; i < 26; i++) {
    int mn = 51;
    
    for(int j = 0; j < n && mn; j++) {
      int tmp = m[j]['a' + i];
      mn = min(mn, tmp);
    }
    for(int j = 0; j < mn; j++) ans += 'a' + i;
  }

  sort(ans.begin(), ans.end());

  O << ans << EN;
  
  return 0;
}
