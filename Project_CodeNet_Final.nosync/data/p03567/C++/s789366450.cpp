#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    getline(cin,a);
    for (int i=0;i<a.size()-1;i++)
    {
    	if (a[i]=='A' && a[i+1]=='C')
    	{
    		cout<<"Yes"<<endl;
    		return 0;
		}
	}
	cout<<"No"<<endl;
    return 0;
}