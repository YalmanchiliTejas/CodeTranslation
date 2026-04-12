#include <bits/stdc++.h>
using namespace std ;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define PI acos(-1.0) 
#define N 111111

const int INF = 1 << 30 ;
typedef long long ll ;
typedef pair < int , int > pii ;

int a[60][27] ;

int main() {
  int n ;
  string s ,ans ;

  scanf("%d", &n) ;

  for(int i = 0 ;i<n ;i++){
    cin >> s ;
    for(int j = 0 ; j<s.length() ; j++)
      a[i][s[j] - 'a']++ ;
  }

  for(int i = 0 ; i<26 ; i++){
    int min_letter = INT_MAX ;
    for(int j = 0; j<n ; j++)
      min_letter = min(min_letter, a[j][i]) ;
    for(int k = 0 ; k<min_letter ; k++)
      ans+=(i+'a') ;
  }
  cout << ans << endl; 	
  return 0 ;
}