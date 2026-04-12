//49
#include<iostream>
#include<string>

using namespace std;

int main(){
  for(char t;cin>>t,t!='#';){
    int s[2]={};
    int l=0;
    string c[4][13];
    for(int i=0;i<4;i++){
      for(int j=0;j<13;j++){
	cin>>c[i][j];
      }
    }
    for(int i=0;i<13;i++){
      int x=l;
      for(int j=0;j<4;j++){
	if(c[j][i][1]!=c[x][i][1]){
	  if(c[j][i][1]==t){
	    x=j;
	  }
	}else{
	  string r="23456789TJQKA";
	  if(r.find(c[j][i][0])>r.find(c[x][i][0])){
	    x=j;
	  }
	}
      }
      s[x%2]++;
      l=x;
    }
    if(s[0]>s[1]){
      cout<<"NS "<<s[0]-6<<endl;
    }else{
      cout<<"EW "<<s[1]-6<<endl;
    }
  }
}