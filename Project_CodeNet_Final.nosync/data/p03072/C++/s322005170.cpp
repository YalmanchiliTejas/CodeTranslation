#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
signed main(){
  	int N;cin>>N;
  	int ans;ans=0;
  	int mt_w;
  	int mt_n;
  	mt_w=0;
  	rep(i,N){
    	cin>>mt_n;
      	if(mt_n>=mt_w){
        	ans=ans+1;
          	mt_w=mt_n;
        }
    }

	cout<<ans<<endl;
	return 0;
}
