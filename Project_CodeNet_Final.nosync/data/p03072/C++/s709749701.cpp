#include<bits/stdc++.h>

using namespace std;

int main(){

	int n;
  cin>>n;
  vector<int>a(n);
  
  for(int i=0;i<n;i++){
  	cin>>a[i];
  }
  
  
  int count =0;
  
  for(int i=0;i<n;i++){
  	bool done = true;
    
    for(int j=i-1;j>=0;j--){
    	if(a[j]>a[i]){
        	done = false;
          	break;
        }
    }
    
    if(done){
    	count++;
    }
  
  }
  
  cout<<count;

}
