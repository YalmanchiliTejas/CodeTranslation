// 簡易競プロテンプレ
#include <bits/stdc++.h>
using namespace std;
string s[8];

int main(void){
 int h, w; cin >> h >> w;
 for(int i=0;i<h;i++) cin >> s[i];
 int cnt = 0;
 for(int i=0;i<h;i++)for(int j=0;j<w;j++) if (s[i][j]=='#') cnt++;  
 cout << ((cnt==h+w-1) ? "Possible" : "Impossible") << endl;
 return 0;
}