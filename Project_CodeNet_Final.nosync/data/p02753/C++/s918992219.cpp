#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long
#define pb push_back
#define mp make_pair
#define mt make_tuple


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// 	int t;
// 	cin>>t;
  string s;
  cin>>s;
  int ok=0;
  for(int i=0;i<2;i++)
 {
     if(s[i]=='A'&&s[i+1]=='B')
    { ok=1;break;}
     if(s[i]=='B'&&s[i+1]=='A')
    { ok=1;break;}
 }
 if(ok)
 cout<<"Yes"<<endl;
 else 
 cout<<"No"<<endl;
    
  
 
	
	return 0;
}
