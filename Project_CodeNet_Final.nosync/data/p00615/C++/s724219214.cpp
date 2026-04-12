#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  
  int t[20000];
  int n,m;

  while(1){
    for(int i=0;i<2000;i++)t[i]=0;

    cin >> n>>m;
    if(n==0&&m==0)break;

    for(int i=0;i<n+m;i++)cin>>t[i];

    sort(t,t+(n+m));

    int max=0;
    for(int i=1;i<n+m;i++){
      if((t[i]-t[i-1])>max&&(t[i]-t[i-1])!=0)max=t[i]-t[i-1];
    }
    if(t[0]>max)cout<<t[0]<<endl;
    else cout << max<<endl;
  }
  
    return 0;
}