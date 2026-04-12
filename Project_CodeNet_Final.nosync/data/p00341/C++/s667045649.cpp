#include<iostream>
using namespace std;

int main(){
  int e[15];
  int result=0;
  for(int i=0;i<12;i++)
    cin>>e[i];
  for(int i=0;i<12;i++){
    int a=e[i];
    int ege=0;
    for(int j=0;j<12;j++){
      if(e[j]==a){
	ege++;
      }
    }
  if(ege%4==0)
    result++;
  if(ege/4==3)
    result=12;
  }
  if(result==12)
    cout<<"yes\n";
  else
    cout<<"no\n";
  return 0;
}

