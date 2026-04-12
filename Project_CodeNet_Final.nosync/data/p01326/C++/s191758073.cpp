#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long lli;

const lli N = 1000;
const lli M = 1000000;

lli n, dp[N+1], t[1001];
string data[N];
string pat[4][4] = {
  {"0xxxxxxx", "", "", ""},
  {"110yyyyx", "10xxxxxx", "", ""},
  {"1110yyyy", "10yxxxxx", "10xxxxxx", ""},
  {"11110yyy", "10yyxxxx", "10xxxxxx", "10xxxxxx"},
};

main(){
  t[0] = 1;
  for(lli i=1;i<1001;i++) t[i] = (t[i-1] * 2) % M;
  while(cin >> n && n){
    for(lli i=0;i<n;i++) cin >> data[i];
    fill(dp, dp+n+1, 0);
    dp[0] = 1;
    for(lli i=0;i<n;i++){
      for(lli j=0;j<4&&i+j<n;j++){
        bool f = true;
        bool f_y = false;
        bool f_y2 = false;
        if(j == 0) f_y = true;
        lli cnt[2] = {0, 0};
        for(lli k=0;k<=j;k++){
          for(lli l=0;l<8;l++){
            if(data[i+k][l] != 'x' && pat[j][k][l] != 'x' && pat[j][k][l] != 'y' && data[i+k][l] != pat[j][k][l]){
              //cout << "# " << j << ' ' << k << ' ' << l << endl;
f = false;
            }
            if(data[i+k][l] == '1' && pat[j][k][l] == 'y') f_y = f_y2 = true;
            if(data[i+k][l] == 'x'){
              if(pat[j][k][l] == 'x') cnt[0]++;
              if(pat[j][k][l] == 'y'){
                cnt[1]++;
                f_y = true;
              }
            }
          }
        }
        //cout << i << ' ' << j << ' ' << f << endl;
        if(!f_y) f = false;
        if(f){
          lli val = t[cnt[0]];;
          //cout << cnt[0] << ' ' << cnt[1] << endl;
          if(cnt[1]){
            if(f_y2) val = (val * t[cnt[1]]) % M;
            else val = (val * ((t[cnt[1]] - 1 + M) % M)) % M;
          }
          //cout << val << endl;
          dp[i+j+1] = (dp[i+j+1] + dp[i] * val) % M;
        }
      }
    }
    cout << dp[n] << endl;
  }
}