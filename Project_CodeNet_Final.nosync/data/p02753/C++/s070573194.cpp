#include<iostream>
using namespace std;
int main()
{
	string s;
  	cin >> s;
    int ac=0,bc=0;
  	for(int i=0;i<3;i++)
    {
      if(s[i]=='A')
        ac++;
      else
        bc++;
    }
  	if(ac==0 || bc==0)
      cout<<"No";
  	else
      cout<<"Yes";
  return 0;
}