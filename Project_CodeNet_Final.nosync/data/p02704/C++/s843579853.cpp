#include <bits/stdc++.h>
using namespace std;

//#define ULL unsigned long long;
typedef uint64_t ULL;
const int M=505;
const ULL INF=0xffffffffffffffff;
int s[M],t[M];
ULL u[M],v[M];
int n;
ULL a[M][M];
vector<int> r,c;

int vis[M];

void solve(ULL p)
{
	if(!r.size()||!c.size()) return;
	//cout<<"here"<<endl;
	if(r.size()>=2&&c.size()>=2)
	{
		if(r.size()>=c.size())
		{
			int j=0;
			for(int i:r)
			{
				a[i][c[j]]|=p;
				j=(j+1)%c.size();
			}
		}
		else
		{
			int j=0;
			for(int i:c)
			{
				a[r[j]][i]|=p;
				j=(j+1)%r.size();
			}
		}
		return;
	}
	//cout<<"here"<<endl;
	if(r.size()==1)
	{
		//cout<<"here"<<endl;
		int i=r[0];
		int cnt0=0,cnt1=0;
		memset(vis,0,sizeof(vis));
		for(int j:c)
			vis[j]=1;
		for(int j=0;j<n;j++)
		{
			if(vis[j]) continue;
			if(a[i][j]&p) cnt1=1;
			else cnt0=1;
		}
		int cntr0=cnt0,cntr1=cnt1;
		
		for(int j:c)
		{
			//cout<<"!!!!! j"<<endl;
			cnt0=cnt1=0;
			for(int k=0;k<n;k++)
			{
				if(k==i) continue;
				if(a[k][j]&p) cnt1=1;
				else cnt0=1;
			}
			//cout<<"!! "<<cnt0<<" "<<cnt1<<endl;
			if(t[j] && (v[j]&p))
			{
				if(!cnt1) a[i][j]|=p,cntr1=1,vis[j]=0;
			}
			if(!t[j] && !(v[j]&p))
			{
				if(!cnt0) cntr0=1,vis[j]=0;
			}
		}

		for(int j:c)
		{
			if(!vis[j]) continue;
			//cout<<"!! j "<<endl;
			if(cntr0&&cntr1) break;
			if(s[i] && (u[i]&p))
			{
				a[i][j]|=p;
				cntr1=1;
			}
			else if(!s[i] && !(u[i]&p))
			{
				cntr0=1;
			}
		}
	}
	else // c.size()==1
	{
		int i=c[0];
		int cnt0=0,cnt1=0;
		memset(vis,0,sizeof(vis));
		for(int j:r)
			vis[j]=1;
		for(int j=0;j<n;j++)
		{
			if(vis[j]) continue;
			if(a[j][i]&p) cnt1=1;
			else cnt0=1;
		}
		int cntr0=cnt0,cntr1=cnt1;
		
		for(int j:r)
		{
			//cout<<"!!!!! j"<<endl;
			cnt0=cnt1=0;
			for(int k=0;k<n;k++)
			{
				if(k==i) continue;
				if(a[j][k]&p) cnt1=1;
				else cnt0=1;
			}
			//cout<<"!! "<<cnt0<<" "<<cnt1<<endl;
			if(s[j] && (u[j]&p))
			{
				if(!cnt1) a[j][i]|=p,cntr1=1,vis[j]=0;
			}
			if(!s[j] && !(u[j]&p))
			{
				if(!cnt0) cntr0=1,vis[j]=0;
			}
		}

		for(int j:r)
		{
			if(!vis[j]) continue;
			//cout<<"!! j "<<endl;
			if(cntr0&&cntr1) break;
			if(t[i] && (v[i]&p))
			{
				a[j][i]|=p;
				cntr1=1;
			}
			else if(!t[i] && !(v[i]&p))
			{
				cntr0=1;
			}
		}
	}
}

bool check()
{
	for(int i=0;i<n;i++)
	{
		ULL cur=s[i]?0:INF;
		for(int j=0;j<n;j++)
		{
			if(s[i]) cur|=a[i][j];
			else cur&=a[i][j];
		}
		//cout<<i<<" "<<cur<<" "<<u[i]<<endl;
		if(cur!=u[i]) return false;
	}
	for(int i=0;i<n;i++)
	{
		ULL cur=t[i]?0:INF;
		for(int j=0;j<n;j++)
		{
			if(t[i]) cur|=a[j][i];
			else cur&=a[j][i];
		}
		//cout<<i<<" "<<cur<<" "<<v[i]<<endl;
		if(cur!=v[i]) return false;
	}
	return true;
}

int main()
{
	//cout<<INF<<" "<<(INF+1)<<endl;
	//cout<<INF<<" "<<ULONG_MAX<<endl;
	//freopen("in.txt","r",stdin);
	// scanf("%d",&n);
	// for(int i=0;i<n;i++)
	// 	scanf("%d",&s[i]);
	// for(int i=0;i<n;i++)
	// 	scanf("%d",&t[i]);
	// for(int i=0;i<n;i++)
	// 	scanf("%llu",&u[i]);
	// for(int i=0;i<n;i++)
	// 	scanf("%llu",&v[i]);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		cin>>t[i];
	for(int i=0;i<n;i++)
		cin>>u[i];
	for(int i=0;i<n;i++)
		cin>>v[i];

	//cout<<"input ok"<<endl;
	ULL p=1;
	for(int ii=0;ii<64;ii++,p<<=1)
	{
		//cout<<ii<<endl;
		//cout<<p<<endl;
		r.clear();
		c.clear();
		for(int i=0;i<n;i++)
		{
			// or 0
			// and 1
			ULL val=u[i]&p;
			if((s[i]&&!val) || (!s[i]&&val))
			{
				for(int j=0;j<n;j++)
					a[i][j]|=val;
			}
			else
				r.push_back(i);
		}
		for(int i=0;i<n;i++)
		{
			// or 0
			// and 1
			ULL val=v[i]&p;
			if((t[i]&&!val) || (!t[i]&&val))
			{
				for(int j=0;j<n;j++)
					a[j][i]|=val;
			}
			else
				c.push_back(i);
		}
		
		// cout<<"r : ";
		// for(int i:r) cout<<i<<" ";
		// cout<<endl<<"c : ";
		// for(int i:c) cout<<i<<" ";
		// cout<<endl;

		// for(int i=0;i<n;i++)
		// 	for(int j=0;j<n;j++)
		// 		printf("%d%c",a[i][j]&p?1:0,j==n-1?'\n':' ');
		// cout<<"here! before solve"<<endl;
		solve(p);
		// for(int i=0;i<n;i++)
		// 	printf("%d%c",u[i]&p?1:0,i==n-1?'\n':' ');
		// for(int i=0;i<n;i++)
		// 	printf("%d%c",v[i]&p?1:0,i==n-1?'\n':' ');
		// cout<<endl;
		// for(int i=0;i<n;i++)
		// 	for(int j=0;j<n;j++)
		// 		printf("%d%c",a[i][j]&p?1:0,j==n-1?'\n':' ');
		// cout<<endl;
	}
	if(check())
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cout<<a[i][j]<<(j==n-1?'\n':' ');
	}
	else
		cout<<"-1\n";
	return 0;
}