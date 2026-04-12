#define _USE_MATH_DEFINES
#include<stdio.h>
#include<string>
#include<iostream>
#include<cctype>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include <algorithm>
#include<math.h>
#include<set>
#include<map>
#include<iomanip>

//#include<bits/stdc++.h>



using namespace std;




int main() {

	int a,b;
	cin>>a>>b;
	int x=0;
	for(int i=0;i<a;i++){
		string p;
		cin>>p;
		for(int j=0;j<p.size();j++)
			if(p[j]=='#')x++;
	}
	if(x==a+b-1)cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
	   
	
	return 0;
}

	