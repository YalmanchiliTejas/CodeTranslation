#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct S{
  S(int a,int b){
    num=a;ac=b;
  }
  int num,ac;
};

bool operator<(S a,S b){
  return a.ac<b.ac;
}

int ans[100];


int main(){
  int num,ac;
  for(int i=0;i<100;i++){
    ans[i]=0;
  }
  vector<S> list;
  while(scanf("%d,%d",&num,&ac),ac!=0||num!=0){
    list.push_back(S(num,ac));
  }
  sort(list.begin(),list.end());
  int tmp=1;
  ans[ list[list.size()-1].num ] =1;
  for(int i=list.size()-2;i>=0;i--){
    if( list[i+1].ac != list[i].ac ){
      tmp++;
    }
    ans[list[i].num]=tmp;
  }
  while(cin>>tmp){
    cout<<ans[tmp]<<endl;
  }
}