#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

#define rep(i,n) for(i=0,i<(n),i++)
using namespace std;

int main() {
	int r,g,b;
	cin>>r>>g>>b;
	r=(r*100)+(g*10)+b;
	if(r%4==0){
		cout<<"YES"<<endl;
	}
	else{
			cout<<"NO"<<endl;
	}
	// your code goes here
	return 0;
}