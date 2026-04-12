#include<iostream>
#include<string>
using namespace std;
int count;
string A="abcdefgqrstvwxz";
string X;

int sA(char ch){
  int g=0;
  for(int i=0;i<A.size();i++){
    if(ch==A[i]){
      g=1;
      break;
  }
  }
  return g;
}
int main(){
  while(1){
    count=0;
    cin >> X;
    if(X[0]=='#')break;
    for(int i=0;i<X.size();i++){

      if(sA(X[i])==1 && i<X.size()-1){
	if(sA(X[i+1])!=1){
	  count++;
	}
      }else{
      if(sA(X[i+1])){
	  count++;
	}
      }
    }
    cout << count << endl;
  }
}