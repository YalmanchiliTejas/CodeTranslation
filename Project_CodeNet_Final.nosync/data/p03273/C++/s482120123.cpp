#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

int gcd(int a,int b){
	if (a%b == 0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}

}
int lcm(int a,int b){
	return a /gcd(a,b) * b;
}







int main() {

   int h,w;
   cin >> h >> w;
   char a[h][w];
   rep (i,h){
     rep (j,w){
      cin >> a[i][j];
     }
   }

  map <int,bool> yoko;
  rep (i,h){
    yoko[i]=true;
    rep (j,w){
      if (a[i][j]=='#'){
        yoko[i]=false;
        break;
      }
    }
  }

  map <int,bool> tate;
  rep (i,w){
    tate[i]=true;
    rep (j,h){
      if (a[j][i]=='#'){
        tate[i]=false;
        break;
      }
    }
  }


  rep (i,h){
    if (yoko[i]) continue;
    rep (j,w){
      if (tate[j]) continue;
      cout << a[i][j];

    }
    cout << endl;
  }
}