#include<iostream>
using namespace std;
typedef pair<int,int> P;
P t[100000];
int n,a,size=0,ans=0;
int main(){
  while(1){
    size=ans=0;
    cin>>n;
    if(n==0)break;
    cin>>a;
    t[size].first=a;
    t[size].second=1;
    for(int i=2;i<=n;i++){
      cin>>a;
      if(i%2==1){
	if(t[size].first==a)t[size].second++;
	else{
	  ++size;
	  t[size].first=a;
	  t[size].second=1;
	}
      }else{
	if(t[size].first==a)t[size].second++;
	else if(size==0){
	  t[size].first=a;
	  t[size].second++;
	}else{
	  size--;
	  t[size].second+=(t[size+1].second+1);
	}
      }
    }
    
    for(int i=0;i<=size;i++){
      if(t[i].first==0)ans+=t[i].second;
    }
    cout<<ans<<endl;
  }
  return 0;
}