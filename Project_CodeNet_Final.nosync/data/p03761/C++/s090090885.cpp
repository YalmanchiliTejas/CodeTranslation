#include <bits/stdc++.h>
using namespace std;

bool c[26];
int s[26];

int main()
{
//	freopen("c.txt","r",stdin);
	
	int len,n;
	char a[51];
	vector<bool> each;
	vector<int> se;
	bool check=false;

	scanf("%d",&n);
	
	for(int i = 0;i < n;i++)
	{
		each.assign(26,false);
		se.assign(26,0);
		
		scanf("%s",a);
		
		len = strlen(a);
		
		for(int j = 0;j < len;j++)
		{
			each[a[j]-'a'] = true;
			se[a[j]-'a']++;
		}
		for(int j = 0;j < 26;j++)
		{
			if(i>0 && c[j] && !each[j]) c[j] = false;
			else if(i==0 && each[j]) c[j] = true;
			if(i==0) s[j] = se[j];
			else if(i>0) s[j] = min(s[j],se[j]);
		}
	}
	for(int i = 0;i < 26;i++)
	{
		if(c[i])
		{
			check = true;
			for(int j = 0;j < s[i];j++) 
				printf("%c",'a'+i);
		}
	}
	//if(!check)
}
			 
	
			