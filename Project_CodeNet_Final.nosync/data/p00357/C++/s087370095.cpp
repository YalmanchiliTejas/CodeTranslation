#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int N;
  cin>>N;
  int jump[N];
  for(int i=0;i<N;i++){
    cin>>jump[i];
  }
  int jum_dis=0;
  for(int i=0;i<N-1;i++){
    jum_dis=max(jum_dis,jump[i]);
    if(jum_dis<10){cout<<"no\n";return 0;}
    jum_dis -= 10;
  }

  jum_dis=0;
  for(int i=0;i<N-1;i++){
    jum_dis=max(jum_dis,jump[N-i-1]);
    if(jum_dis<10){cout<<"no\n";return 0;}
    jum_dis -= 10;
  }

  cout<<"yes\n";
}

