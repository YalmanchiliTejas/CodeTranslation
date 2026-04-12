#include<iostream>

using namespace std;

int main(){
  
  int m;
  
  cin>>m;
  
  for(int j=0;j<m;++j){
    int first;
    int year;
    int n;
    int max=0;
    
    cin>>first;
    cin>>year;
    cin>>n;
    
    for(int i=0;i<n;++i){
      int tnhk;
      double nenri;
      int tesu;
      
      cin>>tnhk>>nenri>>tesu;
      
      int A=first;
      int B;
      
      if(tnhk==1){
	for(int k=0;k<year;++k){
	  B=A*nenri;
	  A=A+B-tesu; 
	}
	if(max<A)
	  max=A;
      }
      
      else if(tnhk==0){
	int t=0;
	for(int k=0;k<year;++k){
	  B=A*nenri;
	  A=A-tesu;
	  t+=B;
	}
	if(max<A+t)
	  max=A+t;
      }
    }
    cout<<max<<endl;
  }
}