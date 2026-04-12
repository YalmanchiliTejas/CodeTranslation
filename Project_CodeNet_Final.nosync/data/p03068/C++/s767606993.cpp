#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a;
	while(scanf("%d",&a)!=EOF)
	{
		string temp;
		cin >> temp;
		int b;
		scanf("%d",&b);
		b--;
		for(int i=0; i<a; i++){
			if(temp[i] != temp[b]) temp[i] = '*';	
		}
		cout << temp << '\n';
	}
	return 0;
}