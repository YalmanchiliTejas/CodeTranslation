#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	int t1=0,t2=0;
	cin>>s;
	for(int i=0;i<3;i++)
	if(s[i]=='A')
	t1++;
	else
	t2++;
	if(t1==0||t2==0)
	printf("No");
	else
	printf("Yes");
    return 0;
}