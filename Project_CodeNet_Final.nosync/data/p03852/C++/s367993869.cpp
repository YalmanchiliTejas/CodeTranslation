#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pi pair<ll,ll>
using namespace std;
int main(){
	//	freopen("in.txt","r",stdin);
	char c;
	string s = "aiueo";
	cin >> c;
  if((int)s.find(c)>=0) cout << "vowel" << endl;
  else cout << "consonant" << endl;
  return 0;
}