#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;
int main(){
	int i=0;
	string a;
	cin >> a;
	for(i=0;i<2; i++)
	{
		if(a[i] != a[i+1]){
			cout <<"Yes"<< endl;
			break;
		}
	}
	//cout << i << endl;
	if(i==2)
	{
		cout<<"No"<<endl;
	}

	return 0;
}