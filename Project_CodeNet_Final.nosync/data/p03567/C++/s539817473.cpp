#include <iostream>
#include <cstring>
using namespace std;
const int N=5+5;

int main()
{
	char a[N];
	cin>>a;
	int n=strlen(a);
	bool f=false;
	for(int i=0;i<n-1;i++){
		if(a[i]=='A' && a[i+1]=='C'){
			f=true;
			break;
		}
	}
	if(f)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}