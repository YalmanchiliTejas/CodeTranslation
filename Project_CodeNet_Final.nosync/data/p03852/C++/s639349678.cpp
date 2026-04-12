#include <bits/stdc++.h>
const int mod = 1e9 + 7;
inline int mul( int x , int y ){ return 1LL * x * y % mod ;}
int power_mod( int x , int y ){int ret = 1;while( y ){if( y & 1 ) ret = mul( ret , x );y >>= 1;x = mul( x , x );}return ret;}
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;
const int maxn = 1e5 + 50;


int main(int argc,char *argv[]){
	//freopen( "in.txt" , "r" , stdin );
	string zhu;
	cin>>zhu;
	if(zhu[0]=='a'||zhu[0]=='e'||zhu[0]=='i'||zhu[0]=='o'||zhu[0]=='u')
		cout<<"vowel"<<endl;
	else
		cout<<"consonant"<<endl;
	
	return 0;
}