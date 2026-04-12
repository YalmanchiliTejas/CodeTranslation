#include <iostream>
#include <algorithm>
#include <string>
using namespace std; 
int main() { 
  int n; 
  while(1) { 
    int a[6]={1,2,3,4,5,6}, sum=1; 
    string x;  
    cin >> n;   
    if(n==0) break;   
    for(int i=0; i<n; i++) {   
      cin >> x;  
      if(x=="North") {  
	swap(a[0],a[1]);  
	swap(a[1],a[5]);   
	swap(a[5],a[4]);   
      } else if(x=="East") { 
	swap(a[0],a[3]);
	swap(a[3],a[5]);  
	swap(a[5],a[2]);   
      } else if(x=="West") { 
	swap(a[0],a[2]);   
	swap(a[2],a[5]);  
	swap(a[5],a[3]);  
      } else if(x=="South") { 
	swap(a[0],a[4]); 
	swap(a[4],a[5]);  
	swap(a[5],a[1]);   
      } else if(x=="Right") { 
	swap(a[1],a[2]);  
	swap(a[2],a[4]);   
	swap(a[4],a[3]);   
      } else if(x=="Left") {
	swap(a[1],a[3]);  
	swap(a[3],a[4]);  
	swap(a[4],a[2]);  
      }    
      sum+=a[0]; 
    }  
    cout << sum << endl; 
  } 
  return 0;
}
