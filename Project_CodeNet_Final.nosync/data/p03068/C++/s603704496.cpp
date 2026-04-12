#include <iostream>
using namespace std;
int main() {

	int size,k;cin>>size;string s;
	cin>>s>>k;
	for(int i=0;i<size;i++)
	{
		if(!(s[i]==s[k-1]))
			s[i]='*';
	}cout<<s<<endl;


    return 0;
}
