#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
int p=1000000007;
 
 
signed main() {
	string k;
	cin >> k;
	int n=k.length();
	int a[n];
	for(int i=0;i<n;i++){
		a[i]=k[n-1-i]-'0';
	}
	int d;
	cin >> d;
	int b1[n][d],b2[n][d][10];
	for(int i=0;i<n;i++){
		for(int j=0;j<d;j++){
			b1[i][j]=0;
			for(int k=0;k<=9;k++){
				b2[i][j][k]=0;
			}
		}
	}
	for(int k=0;k<=a[0];k++){
		b1[0][k%d]++;
		b1[0][k%d]=b1[0][k%d]%p;
	}
	for(int j=0;j<=9;j++){
		for(int k=j;k<=9;k++){
			b2[0][j%d][k]++;
			b2[0][j%d][k]=b2[0][j%d][k]%p;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<d;j++){
			b2[i][j][0]+=(b2[i-1][j][9]%p);
			b2[i][j][0]=b2[i][j][0]%p;
			for(int k=1;k<=9;k++){
				b2[i][j][k]+=((b2[i][j][k-1]%p)+(b2[i-1][(j-k+d*k)%d][9]%p))%p;
				b2[i][j][k]=b2[i][j][k]%p;
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<d;j++){
			b1[i][j]+=(b1[i-1][(j-a[i]+a[i]*d)%d]%p);
			b1[i][j]=b1[i][j]%p;
			if(a[i]>=1){
				b1[i][j]+=(b2[i][j][a[i]-1]%p);
				b1[i][j]=b1[i][j]%p;
			}
		}
	}
	cout << (b1[n-1][0]-1+p)%p;
	// your code goes here
	return 0;
}