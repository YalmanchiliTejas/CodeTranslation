#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;
 
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int begin = (int)'a';
	int end = (int)'z';
	int s = end-begin+1;
	int a[s] = {0};
	int b[s] = {0};
	int ans[s] = {0};
    int j = 1;
	
	
		string t;
		cin>>t;
		int ts = t.size();
		for(int i = 0 ; i < ts ; i++)
		{
			a[(int)(t[i] - 'a')]++;
		}
    
        if(n==1)
        {
            for(int i = 0 ; i < s ; i++)
	{
		while(a[i]--)
		{
			cout<<(char)(i+(int)'a');
		}
	}
            return 0;
        }
    
		string tb;
		cin>>tb;
		int tbs = tb.size();
		for(int i = 0 ; i < tbs ; i++)
		{
			b[(int)(tb[i] - 'a')]++;
		}
	for(int i = 0 ; i < s ; i++)
		{
			ans[i] = min(a[i],b[i]);
           a[i] = 0;
            b[i] = 0;
		}
    
    n = n-2;
    while(n--)
    {
        string t;
		cin>>t;
		int ts = t.size();
		for(int i = 0 ; i < ts ; i++)
		{
			a[(int)(t[i] - 'a')]++;
		}
        for(int i = 0 ; i < s ; i++)
		{
			ans[i] = min(a[i],ans[i]);
            a[i]=0;
		}
        
    }
	for(int i = 0 ; i < s ; i++)
	{
		while(ans[i]--)
		{
			cout<<(char)(i+(int)'a');
		}
	}
	cout<<'\n';
	return 0;
}