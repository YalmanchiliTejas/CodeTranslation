#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 111

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

char input[N][N] ;
bool row[N] , col[N] ;

int main() {
    //#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    //freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //freopen("output.txt", "w", stdout);
    //#endif

    int n, m ;
    vector<string>ans ;
    scanf("%d %d" ,&n ,&m) ;

    for(int i = 0 ;i<n ;i++){
        scanf("%s" ,input[i]) ;
    }

    for(int i = 0 ; i<n ;i++){
      bool ok = true ;
      for(int j = 0 ;j<m ; j++){
        if(input[i][j] == '#'){
          ok = false ;
          break ;
        }
      }
      if(ok)row[i] = true ;
    }

    for(int j = 0 ; j<m ; j++){
      bool ok = true ;
      for(int i = 0 ; i<n ; i++){
        if(input[i][j] == '#'){
          ok =false ;
          break ;
        }
      }
      if(ok)col[j] = true ;
    }

    for(int i = 0 ; i<n ;i++){
      if(!row[i]){
        string s ="" ;
        for(int j =0 ; j<m ;j++){
          if(!col[j])s+=input[i][j] ;
        }
        ans.pb(s) ;
      }
    }

    for(int i = 0 ;i<ans.size() ;i++){
      cout << ans[i] << '\n' ;
    }
   
    return 0 ;
}