#include <bits/stdc++.h> 
using namespace std;
long long n,h[101],ans,b[101],mini=0;
int main(){
	cin>>n;
	int cnt=n;
	for(int i=0;i<n;i++){
		cin>>h[i];}
		for(int i=n;i>0;i--){
			for(int j=0;j<i;j++){
				if(h[i]<h[j]){
				cnt--;
				break;}
		}
	}
		cout<<cnt+1;}
