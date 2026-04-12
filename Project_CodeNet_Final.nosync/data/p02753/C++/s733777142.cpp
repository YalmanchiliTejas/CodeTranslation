#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s; cin>>s;
  int check=0;
  for(int i=0;i<s.size();i++)
    if(s[i]=='A')check++;
       
   if(check==0||check==3)cout<<"No";
   else cout<<"Yes";
       
       return 0;
}