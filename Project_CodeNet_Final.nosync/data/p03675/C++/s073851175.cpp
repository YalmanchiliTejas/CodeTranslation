#include<bits/stdc++.h>
using namespace std;  
#define rep(i,n) for(int i=0;i<(n);i++)  
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pii pair<int,int>
#define piii pair<int,pii>
#define mp make_pair
#define pb push_back  
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second  
const int INF = (INT_MAX/2);
const ll LINF = (LLONG_MAX/2);
const double eps = 1e-14;
const double PI = M_PI;  
#define DEB cout<<"!"<<endl
#define SHOW(a,b) cout<<(a)<<" "<<(b)<<endl
#define SHOWARRAY(ar,i,j) REP(a,i)REP(b,j)cout<<ar[a][b]<<((b==j-1)?((a==i-1)?("\n\n"):("\n")):(" "))
#define DIV 1000000007

int main(){
  int n; cin >> n;
  vi table(n);
  vi ans;
  rep(i,n)  cin >> table[i];
  for(int j = n-1; j > 0; j -= 2)
    ans.pb(table[j]);
  
  if(n%2 == 1)
    ans.pb(table[0]);
  for(int j = n%2; j < n; j += 2)
    ans.pb(table[j]);
  for(int i = 0; i < n; i++){
    cout << ans[i];
    if(i != n-1)
      cout << " ";
    else
      cout << endl;
  }
  return 0;
}