#include<bits/stdc++.h>
#define MAXN 10000

using namespace std;
typedef long long ll;

int main()
{
	//freopen("t.txt","r",stdin);
	int n, max, a[100],j;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	max=a[1];
	int d=1;
	for (int i=2;i<=n;i++){
		
		if (a[i]>=max){
			max=a[i]; d++;
		}
	}
	cout<<d;
}