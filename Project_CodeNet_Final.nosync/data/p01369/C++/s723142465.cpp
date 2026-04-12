#include <cstdio>
#include<set>
#include<string>
#include <iostream>
using namespace std;

int main(void)
{
	set<char> nums1;
	const char a[] = {'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b',' '};
	for(int i=0; a[i]!=' '; i++)
	{ 
		nums1.insert(a[i]);
	}
	
	string c;
	int count=0,flag1=0,flag2;
	
	for(;;)
	{
		count=0;
		cin >> c;
		if(c=="#") break;
		for(int i=0; i<c.size(); i++)
		{
			if(nums1.find(c[i])==nums1.end())
			{
				flag2=0;
			}
			else
			{
				flag2=1;
			}
			
			if(flag1!=flag2 && i!=0) count++;
			flag1=flag2;
		}
		
		cout  << count << endl;
	}
	
	return 0;
}