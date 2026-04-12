#include <iostream>
#include <bits/stdc++.h>
using namespace std;  

 int main(){
          ios::sync_with_stdio(false);
  	  cin.tie(0); 
	  int N; 
	  cin>>N; 
	  vector<int> x(N); 
	  for(int i=0;i<N;i++){ 
		  cin>>x[i]; 
	  }  
	  vector<int> copy=x; 
	  sort(x.begin(),x.end()); 
	  int mid=N/2; 
	  int xmid=x[mid]; 
	  int xm=x[mid-1];

	  for(int i=0;i<N;i++){ 
		if (copy[i]<x[mid]){ 
			cout<<xmid<<" "; 
		}else{ 
			cout<<xm<<" "; 
		} 


	  }

    
    return 0; 
}
