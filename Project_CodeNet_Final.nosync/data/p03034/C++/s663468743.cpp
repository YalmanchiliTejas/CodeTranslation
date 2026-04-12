#include<iostream>
#include<vector>
using namespace std;
int N;
long S[1<<17];
long sum[300][2<<17];
long f(int A,int B)
{
	int dif=A-B;
	int k=(N-1-A)/dif+1;
	if(A%dif==0&&A/dif<k)return-1;
	long now=0;
	if(dif<300)now=sum[dif][0]-sum[dif][k*dif]+sum[dif][A]-sum[dif][A+k*dif];
	else
	{
		for(int i=A;i-A<k*dif&&i<N;i+=dif)now+=S[i];
		for(int i=0;i<k*dif&&i<N;i+=dif)now+=S[i];
	}
	return now;
}
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>S[i];
	for(int i=1;i<300;i++)
	{
		for(int j=N;j--;)sum[i][j]=S[j]+sum[i][j+i];
	}
	long ans=0;
	for(int A=1;A<N;A++)
	{
		int tmp=N-1-A;
		for(int i=1;i*i<=tmp;i++)
		{
			if(tmp%i==0)
			{
				if(A>i)ans=max(ans,f(A,A-i));
				if(tmp/i!=i&&A>tmp/i)ans=max(ans,f(A,A-tmp/i));
			}
		}
	}
	cout<<ans<<endl;
}
