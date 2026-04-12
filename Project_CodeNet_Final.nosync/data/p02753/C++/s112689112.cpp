
#include <bits/stdc++.h>
     
#define pll pair <long long,long long>
#define pb push_back
#define ll long long
#define ff first
#define ss second
#define vll vector <ll>
#define NFS ios_base::sync_with_stdio(0); cin.tie(NULL);
#define endl '\n'
#define M 1000000007   
using namespace std;
 
int main()
{
    NFS
 	string s;
 	cin>>s;
 	if (s[0]=='A' && s[1]=='A' && s[2]=='A')
 	{
 		cout<<"No";
 	}else if(s[0]=='B' && s[1]=='B' && s[2]=='B')
 	{
 		cout<<"No";
 	}else{
 		cout<<"Yes";
 	}
    return 0;
}