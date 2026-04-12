#include <bits/stdc++.h>
#define ll long long int 
#define endl '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX 100000000 
using namespace std;
ll maxi(ll a,ll b)
{
	if(a>=b)
	return a;
	else
	return b;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin>>x;
    if(x>=30)
    {
    	cout<<"Yes"<<endl;
    }
    else
    cout<<"No"<<endl;
}