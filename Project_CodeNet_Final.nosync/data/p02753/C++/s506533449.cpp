#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
  	string s;
  	cin>>s;
  	int a=0,b=0;
  	for(int i=0;i<3;++i){
  		if(s[i]=='A')
  			a++;
  		else
  			b++;
  	}
  	if(a&&b)
  		cout<<"Yes"<<endl;
  	else
  		cout<<"No"<<endl;
}