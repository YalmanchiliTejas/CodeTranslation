#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define gc getchar
#define pb push_back
#define eb emplace_back
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if((a*100+b*10+c)%4)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}