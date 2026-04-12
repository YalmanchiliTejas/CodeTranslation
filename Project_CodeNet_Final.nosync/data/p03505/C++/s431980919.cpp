#include<bits/stdc++.h>
using namespace std;
const long double PI=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline long long read() {
	long long x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return f?-x:x;
}
int main(){
    long long n=read(),a=read(),b=read();
    if(n<=a){cout<<"1\n";return 0;}
    if(b>=a){cout<<"-1\n";return 0;}
	cout<<(long long)ceil((long double)(n-a)/(a-b))*2+1<<"\n";
    return 0;
}