#include<iostream>
using namespace std;
int main(){
 	int j,n,t,s=0;
  	cin>>n;
  	int a[n];
  	for(int i=0;i<n;++i){
      cin>>a[i];
      t=0;
      for(j=0;j<i;j++){
       	if(a[i]<a[j])break;
        t++;
      }
      if(t==i)s++;
    }
  	cout<<s;
  	return 0;
}