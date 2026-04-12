#include <iostream>
using namespace std;

long calc(int way,double ritu,int tesu,long s,int year){
     int rishi=0;
     switch(way){
     case 0:
	  for(int i=0;i<year;i++){
	       rishi+=(int)(s*ritu);
	       s-=tesu;
	  }
	  return s+rishi;
	  break;
     case 1:
	  for(int i=0;i<year;i++){
	       s+=(long)s*ritu;
	       s-=tesu;
	  }
	  return s;
	  break;
     }
     return 0;
}

int main(){
     int M;
     cin>>M;
     int ans[M];

     for(int k=0;k<M;k++){
	  long shikin;
	  int year;
	  cin>>shikin>>year;
	  int N;
	  cin>>N;
	  int karians=0;
	  for(int k1=0;k1<N;k1++){
	       int w,t;
	       double r;
	       cin>>w>>r>>t;
	       karians=max(calc(w,r,t,shikin,year),(long)karians);
	  }
	  ans[k]=karians;
     }
     for(int i=0;i<M;i++)cout<<ans[i]<<endl;
}
	       