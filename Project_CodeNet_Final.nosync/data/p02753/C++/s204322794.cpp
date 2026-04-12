#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define ls x<<1
#define rs x<<1|1
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define fun function
#define vi vector<int>
#define lowbit(x) x&(-x)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

using namespace std;

const int INF = 0x3f3f3f3f;


int main() {
	IOS;
#ifdef xiaofan
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif

	string s;
	cin>>s;
	if(s=="AAA"||s=="BBB")
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl; 




	return 0;
}

