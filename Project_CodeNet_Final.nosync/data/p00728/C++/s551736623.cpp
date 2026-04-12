#include<iostream>
using namespace std;

int main(){
  int n,s;
  
  while(cin>>n && n!=0){
    int sum=0;
    int largest=0;
    int smallest=1000;
    
    for(int i=1;i<=n;i++){
      cin>>s;
      sum+=s;
      if(largest<s)  largest=s;
      if(smallest>s) smallest=s;
    }
    int result=sum-largest-smallest;

    cout<<(int)(result/(n-2))<<endl;
}

}