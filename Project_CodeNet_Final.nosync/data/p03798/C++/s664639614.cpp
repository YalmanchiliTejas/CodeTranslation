#include <iostream>
#include <string>
using namespace std;
 
char data[100000];
char type[2]={'S','W'};
int main(){
 
  int N;
  string s;
  cin>>N;
  cin>>s;
 
  string ans;
  bool exit=false;
  
  for (int first=0;first<2&&!exit;first++)
    for (int second=0;second<2&&!exit;second++)
      {
	data[0]=type[first];
	data[1]=type[second];
	for (int i=1;i<N-1;i++){
	  if(data[i]=='S'){
	    if(s[i]=='o')data[i+1]=data[i-1];
	    else data[i+1]=(data[i-1]=='S')?'W':'S';
	  } else {
	    if(s[i]=='o')data[i+1]=(data[i-1]=='S')?'W':'S';
	    else data[i+1]=data[i-1];
	  }
	}
	bool flag1 = false, flag2 = false;
	if (data[N-1]=='S'){
	  if(s[N-1]=='o'&&(data[N-2]==data[0]))flag1=true;
	  else if(s[N-1]=='x'&&(data[N-2]!=data[0]))flag1=true;
	} else {
	  if(s[N-1]=='o'&&(data[N-2]!=data[0]))flag1=true;
	  else if(s[N-1]=='x'&&(data[N-2]==data[0]))flag1=true;
	}
	if (data[0]=='S'){
	  if(s[0]=='o'&&(data[N-1]==data[1]))flag2=true;
	  else if(s[0]=='x'&&(data[N-1]!=data[1]))flag2=true;
	} else {
	  if(s[0]=='o'&&(data[N-1]!=data[1]))flag2=true;
	  else if(s[0]=='x'&&(data[N-1]==data[1]))flag2=true;
	}
	if (flag1&&flag2)exit=true;
      }
  
  if (exit) {
    for (int i=0;i<N;i++)
      cout<<data[i];
    cout<<endl;
  } else
    cout<<"-1"<<endl;
  
  return 0;
}