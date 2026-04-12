#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;


int main ()
{

int n;
cin >> n;
int arr[n];


int count=0;
for(int i=0;i<n;i++)
{
	cin >> arr[i];
}

bool flag=false;

for(int i=0;i<n;i++)
{
	flag=true;
 for(int j=0;j<i;j++)
 {
 	if(arr[j]>arr[i])
 	{
		flag=false;
		break;
	}

 }
if(flag)
{
	 count++;
}
}

cout << count << endl;

 	return 0;
}










