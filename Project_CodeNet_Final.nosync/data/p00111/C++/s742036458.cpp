#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;

#define PI 3.141592653589793238462643383279
#define mod 1000000007LL
#define rep(i, n) for(i = 0;i < n;++i)
#define rep1(i, n) for(i = 1;i < n;++i)
#define per(i, n) for(i = n - 1;i > -1;--i)
#define int(x) int x; scanf("%d",&x)
#define int2(x, y) int x, y; scanf("%d%d",&x, &y)
#define int3(x, y, z) int x, y, z; scanf("%d%d%d",&x, &y, &z)
#define int4(v, x, y, z) int v, x, y, z; scanf("%d%d%d%d", &v, &x, &y, &z)
#define int5(v, w, x, y, z) int v, w, x, y, z; scanf("%d%d%d%d%d", &v, &w, &x, &y, &z)
#define ll2(x, y) ll x, y; cin >> x >> y;
#define scn(n, a) rep(i, n)cin >> a[i]
#define sc2n(n, a, b) rep(i, n)cin >> a[i] >> b[i]
#define pri(x) cout << (x) << "\n"
#define pri2(x, y) cout << (x) << " " << (y) << "\n"
#define pri3(x, y, z) cout << (x) << " " << (y) << " " << (z) << "\n"
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define endl "\n"
#define kabe puts("---------------------------")
#define kara puts("")
#define debug(x) cout << " --- " << (x) << "\n"
#define debug2(x, y) cout << " --- " << (x) << " " << (y) << "\n"
#define debug3(x, y, z) cout << " --- " << (x) << " " << (y) << " " << (z) << "\n"
#define X first
#define Y second
#define eps 0.0001
#define prid(x) printf("%.15lf\n", x)

string be = " ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string lis[32];
string af = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
string f(int x){
  string res;
  res.resize(5);
  int i;
  per(i, 5){
    res[i] = '0' + (x % 2);
    x /= 2;
  }
  return res;
}

signed main(void){
  int i, j;
  lis[0] = "101";
  lis[1] = "000000";
  lis[2] = "000011";
  lis[3] = "10010001";
  lis[4] = "010001";
  lis[5] = "000001";
  lis[6] = "100101";
  lis[7] = "10011010";
  lis[8] = "0101";
  lis[9] = "0001";
  lis[10] = "110";
  lis[11] = "01001";
  lis[12] = "10011011";
  lis[13] = "010000";
  lis[14] = "0111";
  lis[15] = "10011000";
  lis[16] = "0110";
  lis[17] = "00100";
  lis[18] = "10011001";
  lis[19] = "10011110";
  lis[20] = "00101";
  lis[21] = "111";
  lis[22] = "10011111";
  lis[23] = "1000";
  lis[24] = "00110";
  lis[25] = "00111";
  lis[26] = "10011100";
  lis[27] = "10011101";
  lis[28] = "000010";
  lis[29] = "10010010";
  lis[30] = "10010011";
  lis[31] = "10010000";

  for(int testcase = 0;testcase >= 0;testcase++){

    string s, rmn;
    for(;getline(cin, s);){
      rmn = "";
      rep(i, s.size()){
        rep(j, be.size())if(s[i] == af[j]){
          rmn += f(j);
          break;
        }
      }
      rmn += "        ";

      for(i = 0;i < rmn.size();){
        rep(j, 32)if(rmn.substr(i, lis[j].size()) == lis[j]){
          cout << be[j];
          i += lis[j].size();
          break;
        }
        if(j == 32)break;
      }

      kara;
      s.clear();
    }


/*/

//*/ break;
  }
  return 0;
}