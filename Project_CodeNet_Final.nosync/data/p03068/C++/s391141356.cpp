#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<string>
#include<sstream>
#define ll long long 
#define ld long double
#define rep(i,n) for(i=0;i<n;i++)
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL) 
using namespace std;
int main()
{
	fastio;
	int n,k,i;
    cin>>n;
    string str,a;
    cin>>str;
    cin>>k;
    rep(i,n)
    {
        if (str[i]!=str[k-1])
            a.push_back('*');
        else 
            a.push_back(str[i]);
    }
    cout<<a<<endl;
}