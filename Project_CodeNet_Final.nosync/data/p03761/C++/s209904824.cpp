#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


map<char,int> m_min;

int main() {
  int N;
  scanf("%d", &N);
  string s;
  for (int i = 0; i < N; ++i) {
    cin >> s;
    map<char,int> m;
    int leng = SZ(s);
    FOR(j,0,leng-1){
      ++m[s[j]];
    }
    FOR(j,0,25){
      if(i==0){
        m_min[(char)('a'+j)] = m[(char)('a'+j)];
      }
      else{
        chmin(m_min[(char)('a'+j)],m[(char)('a'+j)]);
      }
    }
  }

  FOR(i,0,25){
    int rep = m_min[(char)('a'+i)];
    FOR(j,1,rep){
      cout << (char)('a'+i);
    }
  }



}

