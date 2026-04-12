//50
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  int m;
  cin>>m;
  while(m--){
    int ia;
    int y,n;
    cin>>ia>>y>>n;
    int ans=0;
    while(n--){
      int k;
      double a;
      int t;
      cin>>k>>a>>t;
      if(k){
	int tmp=ia;
	for(int i=0;i<y;i++){
	  tmp=tmp*(1+a)-t;
	}
	ans=max(ans,tmp);
      }else{
	int r=0,b=ia;
	for(int i=0;i<y;i++){
	  r+=b*a;
	  b-=t;
	}
	ans=max(ans,r+b);
      }
    }
    cout<<(int)ans<<endl;
  }
  return 0;
}