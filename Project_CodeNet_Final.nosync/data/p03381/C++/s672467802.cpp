#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
constexpr int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(), (v).end()
#define vmax 10000
constexpr ll inf = 1e18+7;
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/

int main(){
  cout<<fixed<<setprecision(20);
  cin.tie(0);ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<int> a(n),b(n,0);
  rep(i,n){
    cin>>a[i];
    b[i]=a[i];
  }
  SORT(b);
  rep(i,n){
    if(a[i]<=b[n/2-1]){
      cout<<b[n/2]<<endl;
    }else{
      cout<<b[n/2-1]<<endl;
    }
  }
  return 0;
}
