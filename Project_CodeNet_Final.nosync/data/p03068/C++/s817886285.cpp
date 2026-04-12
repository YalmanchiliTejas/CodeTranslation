#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define FRO freopen("in.txt","r",stdin);


int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n,i,j,t,tcs=0,k,m,u,v;

        string str;
        cin>>n>>str>>k; k--;
        for(i=0;i<n;i++)
        {
                if(str[i]!=str[k]) str[i]='*';
        }
        cout<<str;
	return 0;
}
