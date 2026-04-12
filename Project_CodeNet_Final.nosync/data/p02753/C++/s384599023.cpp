#include<iostream>
#include<vector>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); 
//    cin.tie(NULL); 
    cout.tie(NULL);
  	string s;
  	cin>>s;
  	set<char>st;
  	for(int i=0;i<s.length();i++)
  		st.insert(s[i]);
  	if(st.size()>1)
  		cout<<"Yes";
  	else
  		cout<<"No";
	return 0;
}
