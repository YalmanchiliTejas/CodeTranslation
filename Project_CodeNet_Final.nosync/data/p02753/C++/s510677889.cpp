#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>*/
 
#define pll              pair <long long,long long>
#define pb               push_back
#define ll               long long
#define ff               first
#define ss               second
#define D(x)             cerr<<#x " = "<<(x)<<endl
#define vll              vector <ll>
#define IOS              ios_base::sync_with_stdio(0); cin.tie(NULL);
#define endl             '\n'   
using namespace std;
int main()
{
    IOS
 	// freopen("input.txt","r",stdin);
 	// freopen("output.txt","w",stdout);
 	// freopen("error.txt","w",stderr);
 	string s;
 	cin>>s;
 	set<char>st;
 	for(char x:s)
 	{
 		st.insert(x);
 	}	
 	if(st.size()==2)
 	{
 		cout<<"Yes"<<endl;
 	}
 	else
 	{
 		cout<<"No"<<endl;
 	}
    return 0;
}