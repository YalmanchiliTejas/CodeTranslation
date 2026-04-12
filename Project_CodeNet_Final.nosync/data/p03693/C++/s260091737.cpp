#include<bits/stdc++.h>
using namespace std;
const int N=100000;

int a,b,c,s;
int main ()
{
cin >> a >> b>> c ;
s=b*10+c;
if (s %4==0)
{
	cout << "YES";
	return 0;
}
cout << "NO";
return 0;
}


