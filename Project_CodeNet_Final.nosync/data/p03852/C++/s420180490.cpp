#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 char c;
	 cin>>c;
	 string s="aeiou";
	 if(s.find(c)==string::npos)
	 	cout<<"consonant"<<endl;
	 else
	 	cout<<"vowel"<<endl;
	 return 0;
}