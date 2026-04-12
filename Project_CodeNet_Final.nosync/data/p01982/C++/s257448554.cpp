#include<bits/stdc++.h>
using namespace std;

int main(){
  while(true){
    int n, l, r, count = 0, A[60];
    cin>>n>>l>>r;
    if(!n&&!l&&!r) break;

    for(int i = 1; i <= n; i++){
      cin>>A[i];
    }
    
    for(int i = l; i <= r; i++){
      int flag = !(n%2);
      for(int j = 1; j <= n; j++){
	if(i%A[j] == 0){
	  if(j%2==1){
	    flag = true;
	    break;
	  }else{
	    flag = false;
	    break;
	  }
	}
      }
      if(flag)count++;
    }
    cout<<count<<endl;
  }
  return 0;
}
