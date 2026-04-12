#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char p;
int k;
int num[105];
int tot=0;
ll f[105][4];

ll C(int n,int k){
	if (k<0 || k>n) return 0;
	ll s=1;
	for (int i=0;i<k;i++){
		s *= (n-i);
	}
	for (int i=1;i<=k;i++){
		s /= i;
	}
	return s;
}

ll pwr(int a,int x){
	ll s=1;
	for (int i=1;i<=x;i++){
		s *= a;
	}	
	return s;
}

int main(){
	while (p=getchar()){
		if (p=='\n') break;
		num[++tot]=(int)p-48;
	}
	cin >> k;
	f[0][0]=1;
	for (int i=1;i<=tot;i++){
		f[i][0]=1;
		for (int j=1;j<=k;j++){
			if (num[tot-i+1]==0){f[i][j]=f[i-1][j]; continue;}
			f[i][j] = C(i-1,j) * pwr(9,j); 
			f[i][j] += f[i-1][j-1];
			f[i][j] += ((num[tot-i+1]-1) * C(i-1,j-1) * pwr(9,j-1));
		}
	}
//	for (int i=0;i<=k;i++){
//		for (int j=0;j<=tot;j++){
//			cout << f[j][i] << ' ';
//		}
//		cout << endl;
//	}
	cout << f[tot][k];
	return 0;
}