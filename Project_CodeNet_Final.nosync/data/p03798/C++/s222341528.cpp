#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;

bool judge(int d, char c, int x, int y) {
	if(d==0&&c=='o'&&x==y){return 1;}
	if(d==0&&c=='x'&&x!=y){return 1;}
	if(d==1&&c=='x'&&x==y){return 1;}
	if(d==1&&c=='o'&&x!=y){return 1;}
	return 0;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  string s; cin >> s;

  rep(i, 2) {
    rep(j, 2) {
      int a[N]; // 1 = wolf, 0 = sheep
      a[1] = i;
      a[2] = j;

      for(int i = 3; i <= N; i++) {
				if(a[i - 1] == 0 && s[i - 1] == 'o' || a[i - 1] == 1 && s[i - 1] == 'x') {
				  a[i == N ? 0 : i] = a[i - 2];
        } else {
          a[i == N ? 0 : i] = a[i - 2] ^ 1;
        }
      }

      if(judge(a[1], s[1], a[0], a[2]) && judge(a[0], s[0], a[N-1], a[1])) {
        rep(i, N) {
          if(a[i]) {
            cout << 'W';
          } else {
            cout << 'S';
          }
        }
        cout << endl;
        return 0;
      }
    }
  }

  cout << -1 << endl;
}
