#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl;
#define CNO cout<<"No"<<endl;

typedef long long LL;
typedef long double LD;

int n;
vector<int> a;
vector<int> ans;

void swp(){
  ans.push_back(n-1);
  swap(a[0],a[n-1]);
}

void sft(){
  ans.push_back(1);
  int tmp=a[0];
  rep(i,n-1) a[i]=a[i+1];
  a[n-1]=tmp;
}

int main(){
  cin >> n;
  a=vector<int>(n);
  rep(i,n) cin >> a[i];
  repp(i,1,n){
    while(a[0]!=i) sft();
    while(1){
      sft();
      swp();
      if(a[n-1]==i-1) break;
    }
  }
  sft();
  // rep(i,n) cout << a[i] << " ";
  // cout << endl;
  cout << ans.size() << endl;
  rep(i,ans.size()) cout << ans[i] << endl;
  return 0;
}
