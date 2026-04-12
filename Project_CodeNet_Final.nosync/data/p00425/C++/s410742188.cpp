#include<iostream>
#include<string>
using namespace std;

int main(){
  int n,ue=1,st=6,mg=3,hd=4,me=2,us=5,cnt;
  string moji;
  while(1){
    cin>>n;
    if(n==0)break;
    cnt=1;
    ue=1;st=6;mg=3;hd=4;me=2;us=5;
    for(int i=0;i<n;i++){
      cin>>moji;
      if(moji=="North"){
	us=ue;
	ue=me;
	me=7-us;
	st=7-ue;
      }else if(moji=="East"){
	mg=ue;
	ue=hd;
	hd=7-mg;
	st=7-ue;
      }else if(moji=="West"){
	hd=ue;
	ue=mg;
	mg=7-hd;
	st=7-ue;
      }else if(moji=="South"){
	me=ue;
	ue=us;
	us=7-me;
	st=7-ue;
      }else if(moji=="Right"){
	hd=me;
	me=mg;
	mg=7-hd;
	us=7-me;
	
      }else if(moji=="Left"){
	mg=me;
	me=hd;
	hd=7-mg;
	us=7-me;
      }
      cnt+=ue;
    }
    cout<<cnt<<endl;
  }
  return 0;
}