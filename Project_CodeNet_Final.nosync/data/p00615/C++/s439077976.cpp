
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<complex>
using namespace std ;
typedef vector<int> vi ;
typedef vector<vi> vvi ;
typedef vector<string> vs ;
typedef pair<int, int> pii; 
typedef long long ll ;

#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define rep(i,a) loop(i,0,a)
#define all(a) (a).begin(),(a).end()


int main(void){
  int m, n ;
  while(cin >> m >> n , m + n ){
    vi ans(m+n+1);
    rep(i,n+m)cin>>ans[i];
    ans[n+m]=0;
    sort(all(ans));
    int md = 0;
    rep(i,n+m)md = max(md,ans[i+1]-ans[i]);
    cout << md << endl;
  }
}