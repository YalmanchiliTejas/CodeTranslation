#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define PRINT(a) cout<<a<<"\n"
#define QUO(x,y) (x-x%y)/y
 
int main(){

	int n;
	cin>>n;

	PRINT(800*n-QUO(n,15)*200);

	
	

	return 0;
}