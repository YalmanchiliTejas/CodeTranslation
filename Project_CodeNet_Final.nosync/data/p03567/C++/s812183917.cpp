#include<bits/stdc++.h>
using namespace std;
string n;
int main()
{
    int i,a;
    cin>>n;
    a=n.size()-1;
    for(i=0;i<=a;i++)
    if(n[i]=='A'&&n[i+1]=='C')
    {
    	cout<<"Yes"<<endl;
    	return 0;
    }
	cout<<"No"<<endl; 
    return 0;
}
