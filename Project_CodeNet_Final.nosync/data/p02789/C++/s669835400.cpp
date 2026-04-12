#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

#define MAX(a, b)  a>b?a:b

int main()
{
	int n, m;
	cin>>n>>m;

	if(n==m) { 
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}

	return 0;
}
