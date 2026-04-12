#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x)  x.begin(),x.end()
#define vi vector<int>
#define print(x) for(auto it=x.begin();it!=x.end();it++) cout<<*it<<' '; cout<<'\n';
#define in(x,n) for(int e=0;e<n;e++){int y;cin>>y;x.pb(y);}
#define lower(sl)  transform(sl.begin(), sl.end(), sl.begin(), ::tolower); 
//Available in Snips
#define fi(i, x, y)   for (__typeof(x) i = x; i < y; i ++)
#define fir(i, x, y)  for (__typeof(x) i = x; i > y; i --)
#define fv(x)   for (auto itr = x.begin(); itr != x.end(); itr ++)
#define fvr(x)  for (auto itr = x.end() - 1; itr != x.begin() - 1; itr --)
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here
	string s;
	cin >> s;
	set<char> t;
	for(char x:s){
		t.insert(x);
	}
	if(t.size()>1){
		cout << "Yes";
	}else {
		cout << "No";
	}
	
 
}