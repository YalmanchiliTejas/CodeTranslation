#include<bits/stdc++.h>
#define SIZE 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,s[105];

int main(){
	while(1){
		cin >> n;
		int sum=0;
		if(n==0) break;
		for(int i=0;i<n;i++) cin>>s[i];
		sort(s,s+n);
		for(int i=1;i<n-1;i++) sum+=s[i];
		cout << sum/(n-2) <<endl;
	}
	return 0;
}
