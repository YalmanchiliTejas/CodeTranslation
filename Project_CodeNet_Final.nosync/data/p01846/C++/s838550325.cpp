#include<iostream>
#include<string>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int, int> P;

string str;

int main()
{
  int a,b,c,d;
  int i,j;
  int s[10][10]={};
  int h,w;
  int x;//??£?¶???????????????°
  int cnt;
  int k;

  while(1){

    cin>>str;
    if(str[0]=='#')break;
    cin>>a>>b>>c>>d;
    h=0;
    i=0;
    j=0;
    cnt=0;
    k=0;
    w=0;

    while(i<str.size()){

      if(str[i]>='1' && str[i]<='9'){
	x=str[i]-'0';
	for(;x>0;x--){
	  s[k][cnt]=0;
	  cnt++;
	}
      }else if(str[i]=='b'){
	s[k][cnt]=1;
	cnt++;
      }else if(str[i]=='/'){
	if(k==0)
	  w=cnt;
	cnt=0;
	k++;
	h++;
      }
	i++;

    }//endwhile

    s[a-1][b-1]=0;
    s[c-1][d-1]=1;

    for(i=0;i<h+1;i++){
      x=0;
      for(j=0;j<w;j++){
	if(s[i][j]){//???????????????b?????°???
	  if(x){
	    cout<<x;
	    x=0;
	  }
	  cout<<'b';
	
	}else
	  x++;
	
      }//endforj
      if(x)
	cout<<x;
      if(i<h)
	cout<<'/';
    }//endfori
    cout<<endl;

  }//endwhile1


}