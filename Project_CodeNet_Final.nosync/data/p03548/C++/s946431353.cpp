#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int x,y,z,a,b;
    cin>>x>>y>>z;
    a=x-z;
    b=y+z;
    cout<<a/b;


   return 0;
}
