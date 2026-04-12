#include<bits/stdc++.h>
using namespace std;
const unsigned long long maxn=2e5+5;
const unsigned long long inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    unsigned long long n;
	cin>>n;
    vector<vector<unsigned long long>> ans(n,vector<unsigned long long>(n));
    vector<vector<unsigned long long>> S(4,vector<unsigned long long>(n));
    for(unsigned long long i=0;i<4;i++)
        for(unsigned long long j=0;j<n;j++)
            cin>>S[i][j];
    swap(S[1],S[2]);
    bool ok=true;
    for(unsigned long long q=0;q<2;q++)
	{
        for(unsigned long long z=0;z<64;z++)
		{
            vector<vector<unsigned long long>> T(n,vector<unsigned long long>(n,2));
            vector<vector<unsigned long long>> che(2,vector<unsigned long long>(n,0));
            for(unsigned long long j=0;j<n;j++)
			{
                if(S[0][j]==0&&(S[1][j]&(1uLL<<z)))
				{
                    for(unsigned long long k=0;k<n;k++)
					{
                        if(T[j][k]==0) 
							ok=false;
                        T[j][k]=1;
                        che[0][j]=1;
                    }
                }
                if(S[0][j]==1&&(!(S[1][j]&(1uLL<<z))))
				{
                    for(unsigned long long k=0;k<n;k++)
					{
                        if(T[j][k]==1) 
							ok=false;
                        T[j][k]=0;
                        che[0][j]=1;
                    }
                }
                if(S[2][j]==0&&(S[3][j]&(1uLL<<z)))
				{
                    for(unsigned long long k=0;k<n;k++)
					{
                        if(T[k][j]==0) 
							ok=false;
                        T[k][j]=1;
                        che[1][j]=1;
                    }
                }
                if(S[2][j]==1&&(!(S[3][j]&(1uLL<<z))))
				{
                    for(unsigned long long k=0;k<n;k++)
					{
                        if(T[k][j]==1) 
							ok=false;
                        T[k][j]=0;
                        che[1][j]=1;
                    }
                }
            }
            for(unsigned long long i=0;i<n;i++)
			{
                for(unsigned long long j=0;j<n;j++)
				{
                    if(S[0][i]==0&&!(S[1][i]&(1uLL<<z)))
					{
                        if(S[2][j]==0&&!(S[3][j]&(1uLL<<z)))
						{
                            T[i][j]=0;
                            che[0][i]=1;
                            che[1][j]=1;
                        }
                    }
                    if(S[0][i]==1&&(S[1][i]&(1uLL<<z)))
					{
                        if(S[2][j]==1&&(S[3][j]&(1uLL<<z)))
						{
                            T[i][j]=1;
                            che[0][i]=1;
                            che[1][j]=1;
                        }
                    }
                }
            }
            for(unsigned long long i=0;i<n;i++)
			{
                if(!che[0][i]) 
					continue;
                for(unsigned long long j=0;j<n;j++)
				{
                    if(T[i][j]!=2) 
						continue;
                    if(S[2][j]==0)
					{
                        T[i][j]=0;
                        che[1][j]=1;
                    }
					else
					{
                        T[i][j]=1;
                        che[1][j]=1;
                    }
                }
            }
            for(unsigned long long j=0;j<n;j++)
			{
                if(!che[1][j]) 
					continue;
                for(unsigned long long i=0;i<n;i++)
				{
                    if(T[i][j]!=2) 
						continue;
                    if(S[0][i]==0)
					{
                        T[i][j]=0;
                        che[0][i]=1;
                    }
					else
					{
                        T[i][j]=1;
                        che[0][i]=1;
                    }
                }
            }
            unsigned long long X=q;
            for(unsigned long long i=0;i<n;i++)
			{
                unsigned long long cnt=X;
                for(unsigned long long j=0;j<n;j++)
				{
                    if(T[i][j]!=2) 
						continue;
                    T[i][j]=cnt&1;
                    cnt++;
                }
                if(cnt!=X) 
					X++;
            }
            for(unsigned long long i=0;i<n;i++)
                for(unsigned long long j=0;j<n;j++)
                    ans[i][j]+=((1uLL<<z)*T[i][j]);
        }
        bool check=true;
        for(unsigned long long i=0;i<n;i++)
		{
            unsigned long long now;
            if(S[0][i]==0)
			{
                now=-1;
                for(unsigned long long j=0;j<n;j++)
                    now&=ans[i][j];
            }
			else
			{
                now=0;
                for(unsigned long long j=0;j<n;j++)
                    now|=ans[i][j];
            }
            if(now!=S[1][i]) 
				check=false;
        }
        for(unsigned long long j=0;j<n;j++)
		{
            unsigned long long now;
            if(S[2][j]==0)
			{
                now=-1;
                for(unsigned long long i=0;i<n;i++)
                    now&=ans[i][j];
            }
			else
			{
                now=0;
                for(unsigned long long i=0;i<n;i++)
                    now|=ans[i][j];
            }
            if(now!=S[3][j]) 
				check=false;
        }
        if(check) 
			break;
        else
		{
            for(unsigned long long i=0;i<n;i++)
                for(unsigned long long j=0;j<n;j++)
                    ans[i][j]=0;
        }
    }
    for(unsigned long long i=0;i<n;i++)
	{
        unsigned long long now;
        if(S[0][i]==0)
		{
            now=-1;
            for(unsigned long long j=0;j<n;j++)
                now&=ans[i][j];
        }
		else
		{
            now=0;
            for(unsigned long long j=0;j<n;j++)
                now|=ans[i][j];
        }
        if(now!=S[1][i]) 
			ok=false;
    }
    for(unsigned long long j=0;j<n;j++)
	{
        unsigned long long now;
        if(S[2][j]==0)
		{
            now=-1;
            for(unsigned long long i=0;i<n;i++)
                now&=ans[i][j];
        }
		else
		{
            now=0;
            for(unsigned long long i=0;i<n;i++)
                now|=ans[i][j];
        }
        if(now!=S[3][j]) 
			ok=false;
	}
    if(!ok) 
		cout<<-1<<endl;
    else
	{
        for(unsigned long long i=0;i<n;i++)
        {
            for(unsigned long long j=0;j<n;j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}