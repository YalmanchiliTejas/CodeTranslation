#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int gcd(int a,int b)
{
	if(b==0)
	return a;
	
	return gcd(b,a%b);
}
int power(int x,int y,int p)
{
	int res=1;
	x=x%p;
	while(y>0)
	{
		if(y&1)
		res=(res*x)%p;
		
		y=y>>1;
		x=(x*x)%p;
	}
	return res;
}
struct Matrix{ 
	int a[2][2] = {{0,0},{0,0}};
	Matrix operator *(const Matrix& other){
		Matrix product;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
						product.a[i][k] =product.a[i][k] + (ll)a[i][j]*other.a[j][k];
				}
			}
		}
		return product;
	}
};
int modInverse(int n,int p)
{
	return power(n,p-2,p);
}
int main() {
	// your code goes here
	 ios_base::sync_with_stdio(0);
	 cin.tie(0);
	 int t;
	 cin>>t;
	 if(t>=30)
	 cout<<"Yes";
	 else
	 cout<<"No";
	 return 0;
}
