#include<iostream>
using namespace std;
int l,m,n;
int a,b;
double rate;
int main(){
  int Tc;
  cin>>Tc;
  for(int tc=0;tc<Tc;tc++){
    cin>>l>>m>>n;
    int Ans=0;
    for(int i=0;i<n;i++){
      cin>>a>>rate>>b;
      int ans=l;
      if(!a){
	int sum=0;
	for(int j=0;j<m;j++){
	  int d=ans*rate;
	  sum+=d;
	  ans-=b;
	}
	ans+=sum;
	Ans=max(Ans,ans);
      }else{
	for(int j=0;j<m;j++){
	  int d=ans*rate;
	  ans+=d;
	  ans-=b;
	}
	Ans=max(Ans,ans);
      }
    }
    cout<<Ans<<endl;
  }
  return 0;
}