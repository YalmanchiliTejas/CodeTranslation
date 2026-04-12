#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,ss[550],tt[550],uu[550],vv[550];
int ans[550][550];
int tmp[550][550],rr[550][2],cc[550][2];
signed main()
{
	scanf("%llu",&n);
	int i=1,j=0,k=0;
	while(i<=n)
	{
		scanf("%llu",&ss[i]);
		++i;
	}
	i=1;
	while(i<=n)
	{
		scanf("%llu",&tt[i]);
		++i;
	}
	i=1;
	while(i<=n)
	{
		scanf("%llu",&uu[i]);
		++i;
	}
	i=1;
	while(i<=n)
	{
		scanf("%llu",&vv[i]);
		++i;
	}
	k=0;
	while(k<64)
	{
		memset(tmp,-1ull,sizeof(tmp));
        memset(rr,0,sizeof(rr));
        memset(cc,0,sizeof(cc));
        i=1;
        while(i<=n)
        {
        	int x=(uu[i]&1);
            if(ss[i]^x)
            {
            	j=1;
            	while(j<=n)
				{
            	    if((tmp[i][j]^18446744073709551615ull)&&(tmp[i][j]^x))
            	    {
            	    	printf("-1\n");
            	    	return 0;
            	    }
            	    tmp[i][j]=x;
            	    ++j;
            	}
            }
        	++i;
        }
        i=1;
        while(i<=n)
        {
        	int x=(vv[i]&1);
            if(tt[i]^x)
            {
            	j=1;
            	while(j<=n)
				{
            	    if((tmp[j][i]^18446744073709551615ull)&&(tmp[j][i]^x))
            	    {
            	    	printf("-1\n");
            	    	return 0;
            	    }
            	    tmp[j][i]=x;
            	    ++j;
            	}
        	}
        	++i;
        }
        i=1;
        while(i<=n)
        {
        	j=1;
        	while(j<=n)
        	{
        		if((uu[i]&1)==(vv[j]&1)) tmp[i][j]=(uu[i]&1);
                if(tmp[i][j]==18446744073709551615ull) tmp[i][j]=0;
                ++rr[i][tmp[i][j]];
                ++cc[j][tmp[i][j]];
        		++j;
        	}
        	++i;
        }
        i=1;
        while(i<=n)
        {
        	 if((ss[i])&&(uu[i]&1))
			 {
                if(!rr[i][1])
                {
                	j=1;
	                while(j<=n)
					{
	                    if((!tt[j])&&(!(vv[j]&1))&&(cc[j][0]>1))
						{
	                        tmp[i][j]=1;
	                        --rr[i][0];
							--cc[j][0];
	                        ++rr[i][1];
							++cc[j][1];
	                        break;
	                    }
						++j;
	                }
            	}
            }
        	++i;
        }
        i=1;
        while(i<=n)
        {
        	if((tt[i])&&(vv[i]&1))
			{
                if(!cc[i][1])
                {
                	j=1;
	                while(j<=n)
					{
	                    if((!ss[j])&&(!(uu[j]&1))&&(rr[j][0]>1))
						{
	                        tmp[j][i]=1;
	                        --rr[j][0];
							--cc[i][0];
	                        ++rr[j][1];
							++cc[i][1];
	                        break;
	                    }
	                    ++j;
	                }
            	}
            }
        	++i;
        }
        i=1;
        while(i<=n)
        {
        	if((ss[i]==0)&&((uu[i]&1)==1)&&(rr[i][1]!=n))
        	{
        		printf("-1\n");
        		return 0;
        	}
            if((ss[i]==0)&&((uu[i]&1)==0)&&(rr[i][1]==n))
            {
        		printf("-1\n");
        		return 0;
        	}
            if((ss[i]==1)&&((uu[i]&1)==1)&&(rr[i][1]==0))
            {
        		printf("-1\n");
        		return 0;
        	}
            if((ss[i]==1)&&((uu[i]&1)==0)&&(rr[i][1]!=0))
            {
        		printf("-1\n");
        		return 0;
        	}
            if((tt[i]==0)&&((vv[i]&1)==1)&&(cc[i][1]!=n))
            {
        		printf("-1\n");
        		return 0;
        	}
            if((tt[i]==0)&&((vv[i]&1)==0)&&(cc[i][1]==n))
            {
        		printf("-1\n");
        		return 0;
        	}
            if((tt[i]==1)&&((vv[i]&1)==1)&&(cc[i][1]==0))
            {
        		printf("-1\n");
        		return 0;
        	}
            if((tt[i]==1)&&((vv[i]&1)==0)&&(cc[i][1]!=0))
            {
        		printf("-1\n");
        		return 0;
        	}
        	++i;
        }
        i=1;
        while(i<=n)
        {
        	uu[i]>>=1;
            vv[i]>>=1;
        	j=1;
        	while(j<=n)
        	{
        		if(tmp[i][j]) ans[i][j]|=(1ull<<k);
        		++j;
        	}
        	++i;
        }
		++k;
	}
	i=1;
	while(i<=n)
	{
		j=1;
		while(j<=n)
		{
			printf("%llu%c",ans[i][j],j==n ? '\n' : ' ');
			++j;
		}
		++i;
	}
	return 0;
}
/*
2
0 1
1 0
1 1
1 0
*/