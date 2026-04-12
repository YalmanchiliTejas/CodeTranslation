#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define reps(i, j, n) for(int i = j; i < n; i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const int INF = 1000000001;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int animal[110000];
  //初めの2匹を仮定, 0がwolf, 1がsheep
  bool flag = false;
  rep(i, 2){
    rep(j, 2){
      animal[0] = i; animal[1] = j;
      reps(k, 2, n+1){
        if((animal[k-1] && s[k-1] == 'o')||(!animal[k-1] && s[k-1] == 'x')) animal[k] = animal[k-2];
        else if((animal[k-1] && s[k-1] == 'x')||(!animal[k-1] && s[k-1] == 'o')) animal[k] = (animal[k-2]+1)%2;
      }
      if((animal[n] == animal[0]) && ((animal[0] && (s[0] == 'o' ? animal[1] == animal[n-1] : animal[1] != animal[n-1]))||(!animal[0] && (s[0] == 'o' ? animal[1] !=animal[n-1] : animal[1] == animal[n-1])))){
        flag = true;
        break;
      }
    }
    if(flag) break;
  }
  if(!flag){
    cout << -1 <<endl;
    return 0;
  }
  rep(i, n){
    printf("%c", animal[i] ? 'S' : 'W');
  }
  cout <<endl;
}