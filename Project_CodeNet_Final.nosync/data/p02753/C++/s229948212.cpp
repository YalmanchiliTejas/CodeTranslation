#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    string s;
  	cin>>s;
  	if(count(s.begin(),s.end(),'A')==0 or count(s.begin(),s.end(),'A')==3)
      cout<<"No"<<endl;
  	else
      cout<<"Yes"<<endl;
    
}
