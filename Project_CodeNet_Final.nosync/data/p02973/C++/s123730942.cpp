#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define   ull unsigned long long 
#define mp make_pair
#define pb push_back
const int MAX=2e5+9;
const long long mod=1e9+7;
using namespace std;
vector<int>adj[MAX];
int main(){
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<int>s;
	for(int i=n-1;i>=0;i--){
		int idx=upper_bound(s.begin() , s.end() , a[i])-s.begin();
		if(idx==s.size())
			s.push_back(a[i]);
		else{
			s[idx]=a[i];
		}
	}
	cout<<s.size();

}