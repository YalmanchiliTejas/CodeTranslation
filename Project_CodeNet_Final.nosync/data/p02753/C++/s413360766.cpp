#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
const ll inf = 1e18;
const int nax = 2e6 + 7;

using namespace std;
string s;
int fl1 , fl2;
int main(int argc,char ** argv){
	dhoom;
	cin >> s;
	if(s[0] == 'A' || s[1] == 'A' || s[2] == 'A')
		fl1 = 1;
	if(s[0] == 'B' || s[1] == 'B' || s[2] == 'B')
		fl2 = 1;
	if(fl1 && fl2)
		cout << "Yes" << endl;
	else 
		cout << "No" << endl;
	return 0;
}
