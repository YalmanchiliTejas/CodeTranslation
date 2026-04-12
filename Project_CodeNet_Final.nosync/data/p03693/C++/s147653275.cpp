#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	int r,g,b;
	cin>>r>>g>>b;
	int num=r*100+g*10+b;
	if(num%4)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}