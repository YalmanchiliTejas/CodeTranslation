#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;
void solve()
{
	//Enter your code here Tanmay:)
	//int n;
	string s;
	cin>>s;
	int a=0,b=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='A')
			a++;
		else
			b++;
	}
	if(a==0||b==0)
		cout<<"No";
	else
		cout<<"Yes";
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
int eulortotent(int n)
     {
    //Enter your code here Tanmay:)
    int total=n;
        for(int p=2;p*p<=n;p++)
        {
            if (n%p==0)
        {
            total /= p;
            total *= (p-1);
            while ( n % p == 0 ) 
                n /= p;
        }
    }

    if(n>1)
    {
        total/=n;
        total*=(n-1);
    }

  return total;
}
*/