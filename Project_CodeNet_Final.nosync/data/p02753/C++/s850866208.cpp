#include <iostream>
using namespace std;
int main() {
	char str[4];
	cin>>str;
	cout<<((str[0]==str[1]&&str[0]==str[2])?"No":"Yes")<<endl;
	return 0;
}