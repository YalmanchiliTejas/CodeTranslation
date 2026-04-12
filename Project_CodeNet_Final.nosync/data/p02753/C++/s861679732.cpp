#include <iostream>
#include <string.h>
using namespace std;

int main() {
	
	 char arr[3];
     cin>>arr;
     if ((strcmp(arr,"AAA") == 0) || strcmp(arr,"BBB") == 0)
        cout<<"No";
     else
        cout<<"Yes";
	return 0;
}
