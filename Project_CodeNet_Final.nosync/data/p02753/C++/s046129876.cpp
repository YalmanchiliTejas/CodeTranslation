#include <bits/stdc++.h>
using namespace std;
int main()
{
  	string S;
  	cin>>S;
  	bool is=false;
  	for(int i=1;i<S.length();i++)
    {
    	if(S[i]!=S[i-1])
        {
        	is=!is;
          break;
        }
    }
  	is?cout<<"Yes"<<endl:cout<<"No"<<endl;
	return 0;
}