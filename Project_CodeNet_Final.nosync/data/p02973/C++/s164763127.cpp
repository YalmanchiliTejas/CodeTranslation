#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const int INF = 101001001;
const ll MOD = 1e9 + 7;

int main(){
  int n;
  cin >> n;
  int lis[100000];
  fill(lis, lis + 100000, -1);
  rep(i, n){
    int a;
    cin >> a;
    int k = 0;
    while(a <= lis[k]){
      k++;
    }
    lis[k] = a;
  }
  int i = 0;
  while(lis[i] >= 0) i++;
  cout << i << endl;
}