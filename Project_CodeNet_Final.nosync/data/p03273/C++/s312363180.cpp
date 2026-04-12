/*bismillah ->                                                                                                         << Suirkhanov Meyirlan >>
  GL HF


                                                                                                                      42

    bless my code =)
                                                                                                            NEVER FOLLOW YOUR RULES :D HAHAHAHA
*/


///scanf ("%d%d", &x, &y);
///printf("%d", &a)

#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio();   cin.tie(0);   cout.tie(0);
#define randoperation srand(time(0));
#define pii pair < int , int >
#define pll pair < ll, ll >
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fast ios_base::sync_with_stdio();   cin.tie(0);   cout.tie(0);
#define randoperation srand(time(0));

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll N = 1e3 + 7;
const ld pi = 3.14159265359;
const int INF = 1e9 + 7;
const double eps = 1e-9;

const int xi[4] = {-1, 0, +1, 0};
const int yj[4] = {0, +1, 0, -1};
const int xxi[4] = {+1, 0, -1, 0};
const int yyj[4] = {0, -1, 0, +1};

int n, m;

bool u[N][N];

char a[N][N], ans[N][N];

int main(){

  //freopen("bridge.in", "r", stdin);
  //freopen("bridge.out", "w", stdout);

  fast
  randoperation;

  ///           ||
  ///start here \/

  cin >> n >> m;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> a[i][j];
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){

      /// V

      bool t = 1;

      for(int k = 1; k <= n; k++){
        if(a[k][j] == '#'){
          t = 0;
        }
      }

      if(t){
        for(int k = 1; k <= n; k++){
          u[k][j] = 1;
        }
      }

      /// >

      t = 1;

      for(int k = 1; k <= m; k++){
        if(a[i][k] == '#'){
          t = 0;
        }
      }

      if(t){
        for(int k = 1; k <= m; k++){
          u[i][k] = 1;
        }
      }
    }
  }

  int cnt1 = 0, cnt2 = 0;

  for(int i = 1; i <= n; i++){

    int cnt = 0;

    for(int j = 1; j <= m; j++){
      if(u[i][j]){
        continue;
      }
      else{
        cout << a[i][j];
        cnt++;
      }
    }

    if(cnt == 0){
      continue;
    }
    else{
      cout << '\n';
    }
  }
}
