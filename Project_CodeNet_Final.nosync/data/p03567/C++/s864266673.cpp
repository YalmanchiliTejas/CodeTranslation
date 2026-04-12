#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main(int argc, char* argv[])
{
	string s;
	cin>>s;
	char *p=strstr((char*)s.c_str(),"AC");
	if (p){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}