#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<pii, ll>pi3;
ll mod = 1000000007;
int main()
{
	char a;
	cin >> a;
	//printf("%c%c%c\n", a[0]+'A'-'a',b[0]+'A'-'a',c[0]+'A'-'a');
	//cout << max(a*b,c*d) << endl;
	printf((a == 'a' || a == 'i' || a == 'u'||a=='e'||a=='o') ? "vowel\n" : "consonant\n");
}