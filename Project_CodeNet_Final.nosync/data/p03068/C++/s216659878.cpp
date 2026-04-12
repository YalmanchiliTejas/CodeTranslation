#include<iostream>
#include<string>
using namespace std;

int main(){
	int N;
  	cin>>N;
  	string s;
  	cin>>s;
  	int k;
  	cin>>k;
  	k--;
  	char t=s[k];
  	for(int i=0;i<s.size();++i){
    	if(s[i]!=t)s[i]='*';
    }
	cout<<s<<endl;
  return 0;
}
