#include <iostream>
#include <string>
using namespace std;

int a, b, c;

int solve(string s){
	int tmp;
	if(s=="North")tmp=a, a=b, b=7-tmp;
	else if(s=="East")tmp=c, c=a, a=7-tmp;
	else if(s=="West")tmp=a, a=c, c=7-tmp;
	else if(s=="South")tmp=b, b=a, a=7-tmp;
	else if(s=="Right")tmp=b, b=c, c=7-tmp;
	else if(s=="Left")tmp=c, c=b, b=7-tmp;
	return a;
}

int main(){
	string s;
	int n, sum;
	while(cin>>n, n){
		a=1; b=2; c=3;
		sum=1;
		while(n--){
			cin>>s;
			sum+=solve(s);
		}
		cout<<sum<<endl;
	}
	return 0;
}