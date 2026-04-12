#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;
int main(){
  string a,b;
  int c,d;
  int n[31];
  vector<int> score;
  for(int i=0;i<31;i++)n[i]=0;
  while(true){
    getline(cin,a,',');
    c=atof(a.c_str());
    getline(cin,b,'\n');
    d=atof(b.c_str());
    if(!c)break;
    n[d]++;
    score.push_back(d);
  }
  for(int i=30,k=1;i>=0;i--)if(n[i]>0)n[i]=k++;
  while(cin>>c){
    cout<<n[score[c-1]]<<endl;
  }
  return 0;
}