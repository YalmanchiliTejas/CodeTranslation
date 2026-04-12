#include<iostream>

using namespace std;

int main(){
  int H,W;
  cin>>H>>W;
  char map[8][8];
  int start_pos[8];
  int end_pos[8];
  int i,j;
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      cin>>map[i][j];
      //cout<<map[i][j];
    }
    start_pos[i]=0;
    end_pos[i]=W-1;
  }
  
  int start,end;
  start=0;
  end=0;
  for(i=0;i<H;i++){
    start=0;
    end=0;
    for(j=0;j<W;j++){
      if(start==0 && map[i][j]=='#'){
	start=1;
	start_pos[i]=j;
      }else  if(start==1 && end==0 && map[i][j]!='#'){
	end=1;
	end_pos[i]=j-1;
      }else if(end==1 && map[i][j]=='#'){
	cout<<"Impossible"<<endl;
		return 0;
      }
    }
  }   
    for(i=0;i<H-1;i++){
      //cout<<"start:"<<start_pos[i]<<endl;
      //cout<<"end:"<<end_pos[i]<<endl;
      if(end_pos[i]!=start_pos[i+1]){
	cout<<"Impossible"<<endl;
	return 0;
      }
    }
      cout<<"Possible"<<endl;
    return 0;
    
  
  
}
