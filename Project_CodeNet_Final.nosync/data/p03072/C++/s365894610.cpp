#include<iostream>
#include<vector>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> H(N);
  for(int i=0;i<N;i++)	cin>>H[i];
  int hotel=1;
  int flag=-1;
  for(int i=1;i<N;i++){
    flag=0;
    for(int j=0;j<i;j++){
      if(H[i]<H[j])	flag=1;
    }
    if(flag==0)	hotel++;
  }
  
  cout<<hotel<<endl;
  return 0;
}