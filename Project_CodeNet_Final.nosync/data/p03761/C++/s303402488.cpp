#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  char s[50][51];
  int n,f[50][26]={},i,j;
  vector <char> v;
  cin>>n;
  for(i=0;i<n;i++)
    cin>>s[i];
  for(i=0;i<n;i++){
    for(j=0;s[i][j];j++){
      f[i][(s[i][j]-'a')]++;
    }
  }
  for(i=0;i<26;i++){
    int tmp=51;
    for(j=0;j<n;j++){
      if(!f[j][i])
	break;
      else{
	tmp=min(tmp,f[j][i]);
      }
    }
    if(j==n){
      for(int k=0;k<tmp;k++){
	v.push_back((char)(i+'a'));
      }
    }
  }
  sort(v.begin(),v.end());
  for(i=0;i<v.size();i++){
    cout<<v[i];
  }
  cout<<endl;
  return 0;
}
