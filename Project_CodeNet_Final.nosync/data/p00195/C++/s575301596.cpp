#include<iostream>
#include<algorithm>
using namespace std;


int main(){
	int a[5];
	int x,y;
	while(cin>>x>>y,x|y){
		a[0]=x+y;
		for(int i=1;i<5;i++)cin>>x>>y,a[i]=x+y;
		int *p=max_element(a,a+5);
		cout<<(char)(p-a+'A')<<' '<<*p<<endl;
	}
	return 0;
}