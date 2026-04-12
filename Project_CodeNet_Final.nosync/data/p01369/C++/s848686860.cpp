#include <iostream>

using namespace std;

int main()
{
	char* left="qwertasdfgzxcvb";
	int isleft[128]={};
	for(int i=0;left[i];i++)
		isleft[left[i]]=1;
	
	for(string s;cin>>s,s!="#";){
		int res=0;
		for(int i=1;i<s.size();i++)
			if(isleft[s[i-1]]!=isleft[s[i]])
				res++;
		cout<<res<<endl;
	}
	
	return 0;
}