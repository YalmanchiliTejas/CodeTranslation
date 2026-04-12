#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef pair<int,int> ii;
const int ms= 1e5+9;
vector<int> v1,v2,v3;
int n;

main(){
	cin >> n;
	v1.resize(n);
	v2.resize(n);
	for(int i= 0;i<n;i++) cin >> v1[i];
	sort(v1.begin(),v1.end());
	
	int sz = 0;
	for(int i = 2;i<n;i+=2)
		v2[i] = v1[sz++];
	v2[0] = v1[sz++];
	
	sz = n-1;
	for(int i = 1;i<n;i+=2)
		v2[i] = v1[sz--];
		
	int soma = 0;
	for(int i =1;i<n;i++)
		soma += labs(v2[i] - v2[i-1]);
		
	
	sort(v1.begin(),v1.end(),greater<int>());
	
	sz = 0;

	for(int i = 2;i<n;i+=2)
		v2[i] = v1[sz++];
	
	v2[0] = v1[sz++];
	
	sz = n-1;
	
	for(int i = 1;i<n;i+=2)
		v2[i] = v1[sz--];
	
	int soma1 = 0;
	
	for(int i= 1;i<n;i++)
		soma1 += labs(v2[i-1] - v2[i]);
	
	cout<<max(soma,soma1);
		
}