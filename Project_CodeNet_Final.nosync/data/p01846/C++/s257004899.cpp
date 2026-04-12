#include <bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  while(cin >> S, S != "#") {
    char mas[10][10];
    fill(mas[0], mas[10], '.');
    int w = 0, h = 0, mw = 0;
    for(int i = 0; i < S.size(); i++) {
      mw = max(w, mw);
      if(S[i] == '/') w = 0, h++;
      else if(S[i] == 'b') mas[h][w++] = 'b';
      else w += S[i]-'0';
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b, --c, --d;
    swap(mas[a][b], mas[c][d]);
    string ans = "";
    for(int i = 0; i <= h; i++) {
      int cnt = 0;
      for(int j = 0; j < mw; j++) {
	if(mas[i][j] == 'b') {
	  if(cnt) ans += (char)(cnt+'0');
	  ans += 'b', cnt = 0;
	}
	else cnt++;
	//putchar(mas[i][j]);
      }
      if(cnt) ans += (char)(cnt+'0');
      if(i != h) ans += '/';
      //puts("");
    }
    cout << ans << endl;
  }
  return 0;
}