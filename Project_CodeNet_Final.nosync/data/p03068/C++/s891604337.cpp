#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
signed main(){
	int N;cin>>N;
  	string S;cin>>S;
  	int K;cin>>K;
  	char target;target=S[K-1];
  
  	rep(i,N){
    	if(S[i]!=target)S[i]='*';
    }
  
  	cout<<S<<endl;
  	
  
	return 0;
}
