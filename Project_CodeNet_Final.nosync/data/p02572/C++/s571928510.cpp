//#include <bits/stdc++.h> // header file includes every Standard library
#include<iostream>
#include<vector>
#define MOD 1000000007
using namespace std;
int main() {
	long long int n;
	cin>>n;
	vector<long long int>a(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];
	long long int sum=a[0],need=0;
	for(int i=1;i<n;i++){
		need=(need+a[i]*sum)%MOD;
		sum=(sum+a[i])%MOD;
	}
	cout<<need;
	return 0;
}