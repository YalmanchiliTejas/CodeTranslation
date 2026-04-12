#include<iostream>
using namespace std;

int main(){
  int m;
  cin>>m;

  while(m--){
    long first,year,charge,tmp,t,max=-1;
    int n,r;
    long double per;

    cin>>first>>year>>n;

    while(n--){
      cin>>r>>per>>charge;
      tmp=first;
      t=0;
      for(int i=0;i<year;i++){
	if(r){
	  tmp+=(long)(tmp*per);
	  tmp-=charge;
	}else{
	  t+=tmp*per;
	  tmp-=charge;
	}
      }

      if(!r) tmp+=t;

      if(max==-1||max<tmp)max=tmp;
    }

    cout<<max<<endl;
  }
}