#include<iostream>
using namespace std;

int main(){
  string str[11],str2;
  int N,t=0;
  int po[11][4],sc[11],T;
  
  while(1){
    cin>>N;

    if(N==0) break;

    for(int i=0;i<N;i++){
      cin>>str[i];
      for(int j=0;j<3;j++){
	cin>>po[i][j];
      }
    }
    for(int i=0;i<N;i++){
      sc[i]=po[i][0]*3+po[i][2];
    }
    
    for(int i=0;i<N-1;i++){
      for(int j=N-1;j>i;j--){
	if(sc[j-1]<sc[j]){
	  T=sc[j];
	  sc[j]=sc[j-1];
	  sc[j-1]=T;
	  str2=str[j-1];
	  str[j-1]=str[j];
	  str[j]=str2;
	}
      }
    }
    if(t>0) cout<<endl;
    t++;

    for(int i=0;i<N;i++){
        cout<<str[i]<<","<<sc[i]<<endl;
    }
  }
  return 0;
}