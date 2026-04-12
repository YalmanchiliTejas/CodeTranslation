#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin>>n;
	int h[n];
	for(int i=0;i<n;i++)cin>>h[i];
	int c = h[0],res=1;
	for(int i=1;i<n;i++){
		if(c<=h[i]){
			res++;
			c=h[i];
		}
	}
	cout<<res<<endl;
}
