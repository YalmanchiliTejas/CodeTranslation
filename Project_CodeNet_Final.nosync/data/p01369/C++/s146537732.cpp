#include<iostream>
using namespace std;
bool flg[300];

void make_table(){
  string s="yuiophjklnm";
  for(int i=0;i<(int)s.size();i++){
    flg[(int)s[i]]=true;
  }
}

int main(){
  make_table();
  while(1){
    string str;
    int ans=0;
    cin>>str;
    if(str=="#")break;
    for(int i=1;i<(int)str.size();i++)
      if(flg[(int)str[i-1]]!=flg[(int)str[i]])ans++;
    cout<<ans<<endl;
  }
  return 0;
}