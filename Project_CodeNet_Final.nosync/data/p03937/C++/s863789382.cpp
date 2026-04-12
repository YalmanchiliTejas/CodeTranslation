    #include<cstdio>
     
    int n,m;
    int g[20][20];
    char str[20];
     
    inline int RD()
    {
    	int res=0,k=1;char ch=getchar();
    	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') k=-1;
    	for(;ch>='0'&&ch<='9';ch=getchar()) res=(res<<1)+(res<<3)+ch-'0';
    	return k*res;
    }
     
    int main()
    {
    	n=RD(); m=RD();
    	for(int i=1;i<=n;i++)
    	{		scanf("%s",str);
    			for(int j=0;j<m;j++)
    			{
    				if(str[j]=='#') g[i][j+1]=1;
    				else g[i][j+1]=0;
    			}
    	}
    	
    	int i=1,j=1,flag=0;
    	while(i!=n||j!=m)
    	{
    		if(!g[i+1][j]&&!g[i][j+1])
    			{flag=1;break;}
    		if(g[i-1][j])
    			{flag=1;break;}
    		if(g[i][j-1])
    			{flag=1;break;}
    		if(g[i][j]&&g[i+1][j]&&g[i][j+1])
    			{flag=1;break;}
    		if(g[i][j]&&g[i][j+1])
    		{
    			g[i][j]=0;
    			j++;
    		}
    		else if(g[i][j]&&g[i+1][j])
    		{
    			g[i][j]=0;
    			i++;
    		}
			if((i==n)&&(j==m)&&(g[i][j-1]||g[i-1][j]))
				{flag=1;break;}
    	}
     
    	if(flag) printf("Impossible\n");
    	else printf("Possible\n");
     
    	return 0;
    }
	
	