#include <iostream>
#include <cstring>

using namespace std;


int main() {
    int n,k;
     char str[15];
    cin>>n;
    cin>>str;
    cin>>k;
    int i=0;
    while(str[i])
	{
		if(str[i]==str[k-1])
		cout<<str[i];
		else 
		cout<<"*";
		i++;
	}

    
    return 0;
}