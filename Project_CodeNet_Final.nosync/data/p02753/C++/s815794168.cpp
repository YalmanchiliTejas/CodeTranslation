#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
  cin>>s;
  int a[2]={0};
  for(int i=0;i<s.length();i++){
  	a[s[i]-'A']++;
  }
  if(a[0] && a[1])
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

    return 0;
}