//AnkitCode99 here....
//every ups and downs matter!

#include<bits/stdc++.h>
#define endl "\n"
#define Ryuga ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)

using namespace std;

const ll sz=1e5+5;
const ll szz=1e6+6;
const ll mod=1e9+7;

int main()
{
	Ryuga;

	
	clock_t startTime=clock();

	ll a,b,c;
	cin>>a>>b>>c;
	ll num=a*100 + b*10 +c;
	if(num%4==0)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}

	cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

}//Goodbye...