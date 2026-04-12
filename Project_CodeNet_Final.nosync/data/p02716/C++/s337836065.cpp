/*Code by Codercjh*/
#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a);i<=(b);++i)
#define rf(i,a,b) for(int i=(a);i>=(b);--i)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long ll;
template<typename T>
inline void read(T &x){
	char c=getchar();T fh=0;bool f=false;
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))fh=(fh<<1)+(fh<<3)+(c^48),c=getchar();
	x=f?-fh:fh;
	return;
}
int n;
ll a[200005],sum,f[200005]; 
int main(){
    read(n);
	fr(i,1,n)read(a[i]);
	sum=a[1];
	f[1]=0,f[2]=0;
	fr(i,3,n+1)
	    if(i%2==0)f[i]=max(f[i-2]+a[i-1],f[i-1]);
	    else{
	    	f[i]=max(f[i-2]+a[i-1],sum);
	    	sum+=a[i];
		}
	cout<<f[n+1]<<endl;
	return 0;
}
