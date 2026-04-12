//in the name of god
//if you read this code please search about imam hussain
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back;
#define X first;
#define Y second;
#define pii pair<int,int>;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define read freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

const int maxn=1e5+5;
const int mod=1e9+7;
const int inf=1e9;
const int del=728729;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
int n,a[maxn];
int main(){
	migmig;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	int cnt=1;
	int mx=a[0];
	for(int i=1;i<n;i++){
		if(a[i] >= mx){
			cnt++;
			mx=a[i];
		}
	}
	cout<<cnt;
	return 0;
}

