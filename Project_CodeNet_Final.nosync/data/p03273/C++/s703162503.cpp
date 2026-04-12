#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 105;
int row[N],col[N];
int main()
{
    IOS
 	int n,m;
 	cin>>n>>m;  
 	string s[n];
 	for(int i=0;i<n;i++)
 		cin>>s[i];
 	for(int i=0;i<n;i++)
 	{
 		int c = 0;
 		for(int j=0;j<m;j++)
 			c+=(s[i][j] == '.');
 		if(c == m)
 			row[i] = 1;
 	}	
 	for(int j=0;j<m;j++)
 	{
 		int c = 0;
 		for(int i=0;i<n;i++)
 			c+=(s[i][j]=='.');
 		if(c == n)
 			col[j] = 1;
 	}	
 	for(int i=0;i<n;i++)
 	{
 		if(row[i]) continue;
 		for(int j=0;j<m;j++)
 		if(col[j]) continue;
 		else cout<<s[i][j];
 		cout<<endl;
 	}
    return 0;
}