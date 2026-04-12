//26
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){
  for(int n;cin>>n,n;){
    int d[]={1,2,3,5,4,6};
    int ans=d[0];
    while(n--){
      string s;
      cin>>s;
      int t;
      switch(s[0]){
      case 'N':
	t=d[0];
	d[0]=d[1];
	d[1]=d[5];
	d[5]=d[3];
	d[3]=t;
	break;
      case 'E':
	t=d[0];
	d[0]=d[4];
	d[4]=d[5];
	d[5]=d[2];
	d[2]=t;
	break;
      case 'W':
	t=d[0];
	d[0]=d[2];
	d[2]=d[5];
	d[5]=d[4];
	d[4]=t;
	break;
      case 'S':
	t=d[0];
	d[0]=d[3];
	d[3]=d[5];
	d[5]=d[1];
	d[1]=t;
	break;
      case 'R':
	t=d[1];
	d[1]=d[2];
	d[2]=d[3];
	d[3]=d[4];
	d[4]=t;
	break;
      case 'L':
	t=d[1];
	d[1]=d[4];
	d[4]=d[3];
	d[3]=d[2];
	d[2]=t;
	break;
      }
      ans+=d[0];
    }
    cout<<ans<<endl;
  }
  return 0;
}