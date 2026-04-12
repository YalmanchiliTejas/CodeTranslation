#include <iostream>
using namespace std;
#include <string>
int main() {
    int sum=0,i;
	string s;
	cin>>s;
	if(s.length()==3)
	{
	    for(i=0;i<s.length();i++)
	    {
	        if(s[i]==s[i+1])
	        sum++;
	    }
	    if(sum==2)
	    {
	        cout<<"No"<<endl;
	    }
	    else
	    cout<<"Yes"<<endl;
	}
	return 0;
}