//#include <fsociety>
#include <cmath>
#include <deque>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
//end of libraries ;
#define INF 9999999999
#define N 4000
#define F first
#define S second
#define pb push_back
#define ll long long
#define fcin ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
string s;
int a, b ;
int main(){
fcin;
	cin>>s;
	for(int i = 0 ; i < s.length() ; i++){
		if(s[i]=='A') a++;
		if(s[i]=='B') b++;
	}
	if(a!=0 && b!=0) cout<<"Yes\n";
	else cout<<"No\n";
}