#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	int cnt=0;
	cin>>str;
	cnt=str.find("AC")+1;
	printf("%s\n",cnt?"Yes":"No");
	return 0;
}
