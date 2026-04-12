#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  int highest=0;
  int num=0;
  cin >> N;
  for(int i=0;i<N;i++){
  	int a;cin>>a;
    if(a>=highest){
      highest = a;
      num++;
    }
  }
  cout<<num<<endl;
}
