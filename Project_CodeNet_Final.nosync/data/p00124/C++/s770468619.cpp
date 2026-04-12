#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main(){
  int n;
  int cnt=0;
  string a[50][50][10];
  for(int i=0;i<50;i++)
    for(int j=0;j<50;j++)
      for(int k=0;k<10;k++)
	a[i][j][k]="";
  while(cin>>n,n!=0){
    //    vector<pair<string,int> > s;
    vector<vector<string> > anspo(50);
    for(int i=0;i<n;i++){
      string str;cin>>str;
      int w,l,d;cin>>w>>l>>d;
      //s.push_back(make_pair(str,w*3+d));
      anspo[w*3+d].push_back(str);
    }
    for(int i=49;i>=0;i--){
      for(int j=0;j<anspo[i].size();j++){
	a[cnt][i][j]=anspo[i][j];
      }
    }
    cnt++;
  }
  for(int i=0;i<cnt;i++){
    for(int j=49;j>=0;j--){
      for(int k=0;k<10;k++){
	if(a[i][j][k]!="")
	  cout<<a[i][j][k]<<","<<j<<endl;
      }
    }
    if(i!=cnt-1)
      cout<<endl;
  }
  return 0;
}