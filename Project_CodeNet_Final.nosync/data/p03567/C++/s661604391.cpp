#include <stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin>>s;

	int b=0,c=0;

	int n=s.size();



	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='A' && s[i+1]=='C')
			b=1;
		
	}

	if(b==1)
		cout<<"Yes";

	else
		cout<<"No";
	return 0;
}