    #include<bits/stdc++.h>
    using namespace std;
    long long arr[1000000],arr1[1000000];
    int main()
    {
    	long long x,n,m,y,i,j,k,z,f,pp,qq,rr;
    	cin>>n>>x>>m;
    	arr[0]=1;
		z=0;k=0;
		arr[0]=x%m;
		arr1[x%m]=1;
		f=0;
		z=x;
		for (i=1;i<n;i++)
		{
			arr[i]=(arr[i-1]*arr[i-1])%m;
			if (arr1[arr[i]]==1)
			{
				f=1;
				pp=z;
				for (j=0;j<n;j++)
				{
					if (arr[j]==arr[i])
					{
						break;
					}
					pp-=arr[j];
				}
				qq=j;
				k=i-j;
				break;
			}
			else if (arr[i]==0)
			{
				cout<<z<<endl;
				return 0;
			}
			arr1[arr[i]]=1;
			z=z+arr[i];
		}
		if (f==0)
		{
			cout<<z<<endl;
			return 0;
		}
		z=z+pp*((n-i)/k);
		rr=qq+(n-i)%k;
		for (i=qq;i<rr;i++)
		{
			z=z+arr[i];
		}
		cout<<z<<endl;
    }