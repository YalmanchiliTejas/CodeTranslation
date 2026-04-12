#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;  
  int a[N];
  rep(i,N) cin >> a[i];
  vector<int > ans;
  ans.pb(a[0]);
  rep1(i,N-1){
    int n=ans.size();
    //    rep(i, n) cout << ans[i];
    //    cout << ""<<endl;
    if(ans[0]<a[i]){
      ans[0]=a[i];
    }
    else if(ans[n-1]>=a[i]){
      ans.pb(a[i]);
    }
    else{
      int lb=0;
      int ub=n-1;
      bool update=true;
      while(update){
	update=false;
	int mid=(lb+ub)/2;
	if(ans[mid]>=a[i]){
	  if(mid!=lb) update=true;
	  lb=mid;
	}
	else{
	  if(mid!= ub) update=true;
	  ub=mid;
	}
	//	cout << mid << endl;
      }
      ans[ub]=a[i];
    }    
  }
  cout << ans.size() << endl;
  
  return 0;
    

}
