#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn=1e5+233;
int n,m;
int a[maxn];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	string s;
	cin>>s;
	int k;
	cin>>k;
	char ch=s[k-1];
	int len=s.length();
	for(int i=0;i<n;i++){
		if(s[i]!=ch)s[i]='*';
	}
	cout<<s<<endl;
    return 0;
}
