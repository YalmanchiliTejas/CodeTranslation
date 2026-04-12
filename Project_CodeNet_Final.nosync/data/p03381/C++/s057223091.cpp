#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<long long,long long>
#define reset(a,b) memset(a,b,sizeof a)
#define ll long long
#define MOD 1000000007
#define MID (l+r)/2
#define ALL(x) x.begin(),x.end()
#define dalam fl<=l && r<=fr
#define kiwo 2*(idx),l,MID
#define tengen 2*idx+1,MID+1,r
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mx 200003
#define pc(x) putchar_unlocked(x);

int bit[mx],a[mx],n;
vector<int>ve;

void upd(int idx,int val){
	for(;idx<=n;idx+=idx&-idx)
		bit[idx]+=val;
}

int cari(int idx){
	int ret=0;
	for(;idx;idx-=idx&-idx)
		ret+=bit[idx];
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ve.pb(a[i]);
	}
	sort(ALL(ve));
	for(int i=1;i<=n;i++){
		int in=lower_bound(ALL(ve),a[i])-ve.begin()+1;
		upd(in,1);
	}
	for(int i=1;i<=n;i++){
		int in=lower_bound(ALL(ve),a[i])-ve.begin()+1;
		upd(in,-1);
		int lo=1,hi=n,tengah;
		while(lo<=hi){
			int mid=(lo+hi)/2;
			if(cari(mid-1)<=n/2-1){
				lo=mid+1;
				tengah=mid;
			}
			else hi=mid-1;
		}
		upd(in,1);
		cout<<ve[tengah-1]<<endl;
	}
}