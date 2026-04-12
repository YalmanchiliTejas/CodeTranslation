#include<bits/stdc++.h>
using namespace std;
int mat[100001][101];
int supp[100001][101];
int main(){
	#ifdef EVAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string a;
	int D;
	cin>>a;
	cin>>D;
	for(int i=1;i<=9;i++)mat[0][i%D]++;
	for(int i=1;i<a.length();i++){
		for(int j=1;j<=9;j++){
			mat[i][j%D]++;
		}
		for(int j=0;j<D;j++){
			for(int ki=0;ki<=9;ki++){
				mat[i][(ki+j)%D]+=mat[i-1][j];
				mat[i][(ki+j)%D]%=1000000007;
			}
		}
	}
	int sum=0;
	int sol=0;
	for(int i=0;i<a.length()-1;i++){
		for(int j=0;j<D;j++){
			for(int h=0;h<a[i]-48;h++){
				if((j+h+sum)%D==0)sol+=mat[a.length()-1-i-1][j];
				sol%=1000000007;
			}
		}
		sum+=a[i]-48;
	}
	sum+=a[a.length()-1]-48;
	for(int i=1;i<=sum;i++){
		if(i%D==0)sol++;
		sol%=1000000007;
	}
	cout<<sol;
}