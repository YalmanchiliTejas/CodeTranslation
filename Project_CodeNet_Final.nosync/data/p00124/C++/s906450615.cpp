#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	int i,j,k;
	
	for(k=0;;k++)
	{
		cin >> n ;
		if(n==0)
			break;
		if(k!=0)
			cout << endl;
		string str[11];
		int win[11],lose[11],drow[11];
		int score[11]={0};
		int num[11];
		for(i=0;i<n;i++)
		{
			num[i]=i;
			cin >> str[i] >> win[i] >> lose[i] >> drow[i] ;
			score[i] = win[i]*3+drow[i];
		}
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(score[i]<score[j])
				{
					int a;
					string aa;
					a=score[i];
					score[i]=score[j];
					score[j]=a;
					a=num[i];
					num[i]=num[j];
					num[j]=a;
					aa=str[i];
					str[i]=str[j];
					str[j]=aa;
				}
			}
		}
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(score[i]==score[j] && num[i]>num[j])
				{
					int a;
					string aa;
					a=score[i];
					score[i]=score[j];
					score[j]=a;
					a=num[i];
					num[i]=num[j];
					num[j]=a;
					aa=str[i];
					str[i]=str[j];
					str[j]=aa;
				}
			}
		}
		
		for(i=0;i<n;i++)
		{
			cout << str[i] << "," << score[i] << endl;
		}
	}
}