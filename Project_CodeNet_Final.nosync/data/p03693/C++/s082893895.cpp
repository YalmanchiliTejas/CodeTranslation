// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
    cin >> a >> b >> c;
  	int res = 100*a + 10*b + c;
    (res%4==0) ? cout<<"YES": cout<<"NO";
    return 0;
}