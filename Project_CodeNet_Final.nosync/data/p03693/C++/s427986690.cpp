#include<bits/stdc++.h>
#define RI(x) x = rit()
#define RII(a,b) a = rit(), b = rit()
#define RIII(a,b,c) a = rit(), b = rit(), c = rit()
#define REP(I, N) for(int I=0;I<int(N);I++)
#define REPP(I, N) for(int I=1;I<=int(N);I++)
#define ll long long
#define SZ(x) (int)(x).size()
#define F first
#define S second
#define PB(x) push_back(x)
inline int rit(){
    int f=0,key=1;
    char ch;
    do{
        ch = getchar();
        if(ch=='-') key=-1;;
    }while(ch<'0'||ch>'9');
    do{
        f = f*10+ch-'0';
        ch = getchar();
    }while(ch>='0'&&ch<='9');
    return f*key;
}
using namespace std;
typedef pair<int,int> P;
int ans, a,b,c;
int main(void){
	RIII(a,b,c);
	ans+=a;
	ans = ans*10+b;
	ans = ans*10+c;
	printf("%s\n",ans%4?"NO":"YES");
}