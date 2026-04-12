#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
	string S;
	cin>>S;
	if (!S.compare("AAA") || !S.compare("BBB")){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
	return 0;
}