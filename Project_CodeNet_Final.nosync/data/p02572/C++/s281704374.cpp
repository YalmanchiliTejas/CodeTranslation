#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define re return
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
inline __int128 read(){
    __int128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline void print(__int128 x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}

signed main()
{
	__int128 n=read();
	__int128 sum1=0,sum2=0;
	while (n--){
		int a;
		cin>>a;
		sum1+=a;
		sum2+=a*a;
	}
	sum1=sum1*sum1-sum2;
	sum1/=2;
	sum1%=(__int128)(1e9+7);
	print(sum1);
	re 0;
}
