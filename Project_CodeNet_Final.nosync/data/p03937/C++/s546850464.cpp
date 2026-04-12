#include<bits/stdc++.h>
using namespace std;
int main(){
 int h,w;
 cin>>h>>w;
 vector<string> vec;
 for(int i=0;i<h;i++){
  string t;
  cin>>t;
  vec.push_back(t);
 }
 int ans=0;
 for(int i=0;i<h;i++){
  for(int j=0;j<w;j++){
   if(vec[i][j]=='#'){
    ans++;
   }
  }
 }
 if(ans==h+w-1){
  cout<<"Possible"<<endl;
 }else{
  cout<<"Impossible"<<endl;
 }
 return 0;
}
 