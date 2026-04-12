#include<iostream>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int n;
  long long array[200005]={0};
  long long sum=0;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>array[i];
    array[i]=array[i]+array[i-1];
  }
  
  for(int i=1;i<n;i++){
    long long a=array[i]-array[i-1];
    sum=(sum+((array[n]-array[i])%MOD*a)%MOD)%MOD;
  }
    
  cout<<sum<<endl;
  return(0);
}