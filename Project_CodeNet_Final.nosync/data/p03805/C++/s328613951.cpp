#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int n, m;
vector<int> v[8];
int ans = 0;

int main(){
  cin >> n >> m;
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--;b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  vector<int> ord;
  rep(i, n-1) ord.push_back(i+1);
  do{
    int x = 0;
    for(int i = 0; i < n-1; i++){
      if(find(all(v[x]), ord[i]) != v[x].end()){
        x = ord[i];
      }else{
        break;
      }
      if(i == n-2) ans++;
    }
  }while(next_permutation(all(ord)));
  cout << ans <<endl;
}