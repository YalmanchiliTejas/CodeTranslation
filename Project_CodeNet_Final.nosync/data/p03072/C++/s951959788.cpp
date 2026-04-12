#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
typedef long long ll;
using namespace std;

int main(void){
  int n;
  int h[20];
  int max=0;
  int ans=0;
  cin>>n;
  for(int i=0;i<n;i++){
    
	cin>>h[i];
    if(h[i]>=max){
     ans++;
      max=h[i];
    }
  }
  cout<<ans<<endl;
  

    return 0;
}
