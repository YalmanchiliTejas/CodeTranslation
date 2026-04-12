#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	int n, k;
  	string str;
    cin>>n;
  	cin>>str;
    cin>>k;
  	char ch = str[k-1];
  	for(int i = 0; i < str.size(); i++)
    {
      if(str[i] != ch)
        str[i] = '*';
    }
  cout<<str;
	return 0;
}