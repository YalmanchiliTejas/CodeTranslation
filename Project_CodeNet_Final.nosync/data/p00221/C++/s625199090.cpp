#include<bits/stdc++.h>
using namespace std;
int main(){
  int m,n;

  while(1){
    
    cin>>m>>n;
    
    if(m==0 && n==0)break;
    
    int a[10000];
    string b[10000];
    int c[10000];
    int k[10000];
    
    for(int i=0;i<n;i++){
      cin>>b[i];
      if((i+1)%15==0 ){
	if(b[i]=="FizzBuzz"){a[i]=1;}else{a[i]=0;}
      }else if((i+1)%3==0){
	if(b[i]=="Fizz"){a[i]=1;}else{a[i]=0;}
      }else if((i+1)%5==0){
	if(b[i]=="Buzz"){a[i]=1;}else{a[i]=0;}
      }else if(b[i]!="FizzBuzz"&&b[i]!="Buzz"&&b[i]!="Fizz"){
	c[i]=atoi(b[i].c_str());
	int d=i+1;
	if(c[i]==d){a[i]=1;}else{a[i]=0;}
      }else{a[i]=0;}
  
    }
    
    for(int i=0;i<=m;i++){k[i]=1;}
    int e=0;
    int count=0;
    int t=0;
    int q=0;

    for(int i=0;i<n;i++){
      
      for(int j=0;j<m;j++){
	if(k[j]==0){count++;}
      }
      if(count==m-1){
	for(int j=0;j<m;j++){
	  if(k[j]==1){
	    q++;
	    if(q==1){cout<<j+1;}
	    else{cout<<" "<<j+1;}
	  }
	}
	cout<<endl;
	i=n;
	t=1;
      }
      else if(k[e]==0){
	e++;
	i--;
      }else if(a[i]==0){
	k[e]=0;
	e++;
      }else if(a[i]==1){
	k[e]=1;
	e++;
      }
      if(e>m-1){e=0;}
      else{count=0;}
    }

    q=0;
    if(t!=1){
      for(int i=0;i<m;i++){
	if(k[i]==1){
	  q++;
	  if(q==1){cout<<i+1;}
	  else{cout<<" "<<i+1;}
	}
      }
      cout<<endl;
      
    }
  }
}

