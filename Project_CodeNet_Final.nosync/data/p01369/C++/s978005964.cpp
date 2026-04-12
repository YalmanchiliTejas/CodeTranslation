//28
#include<iostream>
#include<string>

using namespace std;

int main(){
  for(string s;cin>>s,s!="#";){
    int p=-1;
    int c=0;
    for(int i=0;i<s.size();i++){
      string rh="yuiophjklnm";
      int n=rh.find(s[i])==string::npos;
      c+=p!=n;
      p=n;
    }
    cout<<c-1<<endl;
  }
  return 0;
}