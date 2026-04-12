
#include <bits/stdc++.h>


using namespace std;
double pi=3.14159265358979323846264338;


inline void ex(){cout<<"Yes"<<endl;exit(0);}
long long a,b,c,d;


long long n,k,ind;
bool ok[1000001];
long long arr[11][3];
map<long long,long long>ma;
long long arr3[200001];
long long N;
long long T(long long t){
	if(t<0)return t+N;
	else return t%N;
}
long long calc(long long a,long long b){
	long long cnt=1;
	while(b%a==0){
		b=b/a;
		cnt++;
	}
	return cnt;
}
long long ca(long long x,long long y){
	if(ma.find(x%y)!=ma.end()){
		b=0;
		for(int i=0;i<ma[x%y];i++)b+=arr3[i];
		c=0;
		d=ma[x%y];
		for(int i=ma[x%y];i<ind;i++)c+=arr3[i];
		return ind;
	}

	arr3[ind]=x%y;
	ma[x%y]=ind;
	ind++;
	
	
	//cout<<x%y<<endl;
	
	if(x%y==0){b=0;return ind;}
	return ca(T(x*x),y);
	
}

int main(){
	ind=1;
	cin>>n>>a>>N;
	c=0;
	arr3[0]=a;
	ma[a]=0LL;
	ok[a]=true;
	ca(T(a*a),N);
	long long cnt=0;
	//cout<<ind<<endl;
	if(c==0){
		cnt=0;
		for(int i=0;i<min(n,ind);i++)cnt+=arr3[i];
		cout<<cnt<<endl;
		return 0;
	}
	cnt=((n-d)/(ind-d))*c;
	if(n<d){
		for(int i=0;i<n;i++)cnt+=arr3[i];
	}else cnt+=b;
	//cout<<d<<" "<<ind<<endl;
	for(int i=0;i<(n-d)%(ind-d);i++)cnt+=arr3[d+i];
	cout<<cnt<<endl;
	return 0;

}