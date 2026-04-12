#include<iostream>
using namespace std;
int main(){
  while(1){
  int n,a,b,c,x;
  cin>>n>>a>>b>>c>>x;
  if(n==0)break;
  int y,cnt=-1;
  for(int i=0;i<n;i++){
    cin>>y;
    while(y!=x&&cnt<=10000){
      x=(a*x+b)%c;
      cnt++;
    }
    if(x==y) x=(a*x+b)%c,cnt++;
  }
  if(cnt>10000)cout<<"-1"<<endl;
  else cout<<cnt<<endl;
}
  return 0;
}