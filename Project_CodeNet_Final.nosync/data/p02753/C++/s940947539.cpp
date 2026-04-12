#include<bits/stdc++.h>
using namespace std;

/*freopen("testcases/17.in", "r", stdin);
    freopen("output.txt", "w", stdout);*/

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int br1=0,br2=0;
	string s;
	cin >> s;
	if(s[0]=='A')
        br1++;
    else
        br2++;
    if(s[1]=='A')
        br1++;
    else
        br2++;
    if(s[2]=='A')
        br1++;
    else
        br2++;
    if(br1>0 && br2>0)
        cout << "Yes";
    else
        cout << "No";
}
