#include<bits/stdc++.h>
using namespace std;

#define reps(i,j,n) for(int i = (j) ; i < (int)(n) ; ++i)    
#define rep(i,n) reps(i,0,n)  
#define each(it,c) for(__typeof (c).begin() it = (c).begin(); it != (c).end(); it++)  
  
#define all(v) (v).begin(), (v).end()  
#define pb(x) push_back(x)  
#define sz(x) (int)((x).size())  
#define UNQ(s) {sort(ALL(s));(s).erase(unique(ALL(s)),(s).end());}   
#define fr first  
#define sc second  
  
typedef pair< int , int > Pi;  
typedef pair< int , Pi > Pii;

  
typedef long long int64;  
const int INF = 1 << 30;  
  
template<typename T1, typename T2> istream& operator>>(istream& is, pair<T1,T2>& a){ return is>>a.first>>a.second; }  
template<typename T1, typename T2> ostream& operator<<(ostream& os, pair<T1,T2>& a){ return os<<a.first<<" "<<a.second; }  
template<typename T> istream& operator>>(istream& is, vector< T >& vc){ rep(i,sz(vc)) is >> vc[i]; return is;}  
template<typename T> ostream& operator<<(ostream& os, vector< T >& vc){ rep(i,sz(vc)) os << vc[i] << endl; return os; }  

int main(){
  int n;
  vector< vector< int > > vc( 5, vector< int >(5));

  int dp[6][4][4][4][4];
  int temp[] = { 0, 60, 70, 80};


  cin >> n;
  while(n--){
    cin >> vc;

    fill_n( ****dp, 6 * 4 * 4 * 4 * 4, -1);
    dp[0][0][0][0][0] = 0;

    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 4; j++){
        for(int k = 0; k < 4; k++){
          for(int l = 0; l < 4; l++){
            for(int m = 0; m < 4; m++){
              if(dp[i][j][k][l][m] == -1) continue; /* 一番下足してないかも >< */

              for(int o = 0; o < 4; o++){
                for(int p = 0; p < 4; p++){
                  for(int q = 0; q < 4; q++){
                    for(int r = 0; r < 4; r++){
                      int cost = 0;

                      if(vc[i][0] != 0) cost += temp[(vc[i][0] - 1 + j + o) % 4];
                      if(vc[i][1] != 0) cost += temp[(vc[i][1] - 1 + j + k + o + p) % 4];
                      if(vc[i][2] != 0) cost += temp[(vc[i][2] - 1 + k + l + p + q) % 4];
                      if(vc[i][3] != 0) cost += temp[(vc[i][3] - 1 + l + m + q + r) % 4];
                      if(vc[i][4] != 0) cost += temp[(vc[i][4] - 1 + m + r) % 4];

                      dp[i + 1][o][p][q][r] = max( dp[i + 1][o][p][q][r], dp[i][j][k][l][m] + cost);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    cout << dp[5][0][0][0][0] << endl;
  }
}