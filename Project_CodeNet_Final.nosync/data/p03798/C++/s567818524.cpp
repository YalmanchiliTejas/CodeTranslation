#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int,int> P;
typedef long long int ll;

int N;
char s[100001];

bool check(int n1, int n2, int n3, string &tmp){
  
  if(s[n1]=='o'){
    if(tmp[n1]=='S' && tmp[n2]==tmp[n3]) return true;
    if(tmp[n1]=='W' && tmp[n2]!=tmp[n3]) return true;
  }
  if(s[n1]=='x'){
    if(tmp[n1]=='S' && tmp[n2]!=tmp[n3]) return true;
    if(tmp[n1]=='W' && tmp[n2]==tmp[n3]) return true;
  }
  
  return false;
}

bool order(char a, char b, string& tmp){
  
  tmp[0]=a;
  tmp[1]=b;
  
  for(int i=1; i<N-1; i++){
    if(s[i]=='o'){
      if(tmp[i]=='S') tmp[i+1]=tmp[i-1];
      if(tmp[i]=='W'){
	if(tmp[i-1]=='S') tmp[i+1]='W';
	if(tmp[i-1]=='W') tmp[i+1]='S';
      }
    }
    if(s[i]=='x'){
      if(tmp[i]=='S'){
	if(tmp[i-1]=='S') tmp[i+1]='W';
	if(tmp[i-1]=='W') tmp[i+1]='S';
      }
      if(tmp[i]=='W') tmp[i+1]=tmp[i-1];
    }
  }
  return (check(N-1,N-2,0,tmp) && check(0,1,N-1,tmp));
}

int main(){

  ios_base::sync_with_stdio(false);
  cin>>N>>s;
  string t(N+1,' ');
  
  if(order('S','S', t)){
    cout<<t<<endl;
  }
  else if(order('S','W', t)){
    cout<<t<<endl;
  }
  else if(order('W','W', t)){
    cout<<t<<endl;
  }
  else if(order('W','S', t)){
    cout<<t<<endl;
  }
  else{
    cout<<"-1"<<endl;
  }
  return 0;
}
