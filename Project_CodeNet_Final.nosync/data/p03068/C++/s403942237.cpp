#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n,k;
	cin >> n;
	string s; 
	cin >>s >>k;
	char s0=s[k-1];
	for (int i=0;i<n;i++){
    	if(s[i]!=s0){
        	cout <<"*";
        }else {
        	cout << s[i];
        }
    }
	cout << endl;
	return 0;
}