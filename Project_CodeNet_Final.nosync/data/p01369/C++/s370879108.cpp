#include<iostream>
#include<string>
using namespace std;
int main(){
  while(1){
    string a;
    int ans=0,b=0,d=0;
    cin>>a;
    if(a[0]=='#')break;
    if(a.size()!=1){
      for(int i=0;i<a.size();i++){
	int c=a[i]-'a';
	if(c==24||c==20||(7<=c&&c<=15)){
	  b=1;
	}
	else b=0;
	if(i!=0){
	  if(d!=b){
	    ans++;
	    d=b;
	  }
	}else{
	  d=b;
	}
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}