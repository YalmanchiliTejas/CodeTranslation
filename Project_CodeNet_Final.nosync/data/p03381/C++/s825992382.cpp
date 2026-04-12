#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define REP(i,j) for(int i=0;i<j;i++)
#define FORN(i,j,k) for(int i=j;i<k;i++)
#define vi vector<int>
#define vvi vector<vi >
#define pii pair<int,int>
#define vpii vector<pii >
using namespace std;
int n;
int a[200005],b[200005];
int main(void){
	cin>>n;
	REP(i,n){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	int larger=b[n/2],smaller=b[n/2-1];
	REP(i,n){
		if(a[i]<=smaller)cout<<larger<<endl;
		else cout<<smaller<<endl;
	}
	return 0;
}