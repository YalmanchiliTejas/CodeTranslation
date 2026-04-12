#define rep(i,n) for(int i=0;i<n;i++)
#define m_p make_pair
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
int main(){
 string s;
 cin>>s;
 if(s[0]==s[1]&&s[1]==s[2])cout<<"No";
 if(s[0]==s[1]&&s[1]!=s[2])cout<<"Yes";
 if(s[0]!=s[1]&&s[1]==s[2])cout<<"Yes";
 if(s[0]==s[2]&&s[0]!=s[1])cout<<"Yes";
return 0;
}
