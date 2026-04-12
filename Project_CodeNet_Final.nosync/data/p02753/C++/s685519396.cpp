#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
char s[N];

int main() {
	cin>>s;
    char cur = s[0];
  	if(s[1] == cur && s[2] == cur){
		cout<<"No"<<endl;
    }else {
    	cout<<"Yes"<<endl;
    }
    return 0;
}
