#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

#define x first
#define y second
#define pb push_back
#define MX 100007

int fx[4]={1,-1,0,0};
int fy[4]={0,0,1,-1};
int n,m;


int main()
{
	int n;
	cin >>n;
	string s;cin >>s;
	int k;cin >>k;
	k--;
	char c=s[k];

	for(int i=0;i<n;i++){
		if(s[i]!=c){
			s[i]='*';
		}
	}
	cout << s<<endl;
}