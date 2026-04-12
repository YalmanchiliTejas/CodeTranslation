#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin>>N;
  int see =1;
  int H[N];
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  for(int i=1;i<N;i++){
    int k=i;
    
    while(k>0){
      if(H[i]>=H[k-1]){
	k--;
      }else{
	break;
      }
      if(k<=0) see++;
    }
    
  }
  cout<<see<<endl;
  return 0;
}
