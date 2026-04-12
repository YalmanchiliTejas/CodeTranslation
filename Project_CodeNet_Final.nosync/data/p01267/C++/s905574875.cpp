#include<iostream>

using namespace std;

int N,A,B,C,X;
int data[100];
 
int solve(){
  int res = 0;
  int p = 0;
  while(1){
    if(data[p]==X)p++;
    if(p==N)return res;
    res++;
    X=(A*X+B)%C;
    if(res>10000)return -1;
  }
  return res;
}
 
int main(){

  int i;
  
  while(1){
    cin>> N >> A >> B >> C>> X;
    if(N==0&&B==0&&C==0&&X==0)
      break;

    for(i=0;i<N;i++){
      cin>>data[i];
    }
    cout << solve() << endl;
  }
  return 0;
}
