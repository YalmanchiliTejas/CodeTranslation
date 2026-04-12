#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, l, r, A[4000];

signed main(){
  
  while(1){
    
    cin>>n>>l>>r;
    if( !n && !l && !r ) break;
    
    for(int i=1;i<=n;i++) cin>>A[i];
    
    int ans = 0;
    
    for(int num=l;num<=r;num++){
      
      int idx = 0;
      
      for(int i=1;i<=n;i++){
	
	if( num % A[i] == 0 ){
	  idx = i;
	  break;
	}
	
      }
      
      if( idx ) ans += idx % 2;
      else ans += n % 2 == 0;
      
    }
    
    cout<<ans<<endl;
    
  }
  
  return 0;
}

