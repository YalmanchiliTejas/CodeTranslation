#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

long long int a[200001]={};
long long int n;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    if(n==1){
      cout<<a[0]<<endl;
    }
    else if(n%2==1){
      for(long long int i=n;i>=1;i-=2)cout<<a[i-1]<<' ';
      for(long long int i=2;i<n-1;i+=2)cout<<a[i-1]<<' ';
      cout<<a[n-2]<<endl;
    }else{
      for(long long int i=n;i>=2;i-=2)cout<<a[i-1]<<' ';
      for(long long int i=1;i<n-1;i+=2)cout<<a[i-1]<<' ';
      cout<<a[n-2]<<endl;
    }
}
