#include<bits/stdc++.h>
using namespace std;

typedef struct{
  int num,sol,rank;
}set_c;

bool asc( const set_c& left , const set_c& right ){
  return left.sol>right.sol;
}

int main(){

  int key;
  vector< set_c > dat;
  set_c work;

  while(scanf("%d,%d",&work.num,&work.sol) , work.num!=0||work.sol!=0){
    work.rank=0;
    dat.push_back(work);
  }
  
  sort(dat.begin(),dat.end(),asc);
  

  //Rank
  int r=1;
  dat[0].rank=1;
  for(int i=1; i<(int)dat.size(); i++){
    if(dat[i].sol==dat[i-1].sol){
      dat[i].rank=r;
    }
    else{
      dat[i].rank = ++r;
    }
  }


  while(cin>>key){
    for(int i=0; i<(int)dat.size(); i++){
      if(dat[i].num == key ){
	cout << dat[i].rank << endl;
	break;
      }
    }
  }


  return 0;
}