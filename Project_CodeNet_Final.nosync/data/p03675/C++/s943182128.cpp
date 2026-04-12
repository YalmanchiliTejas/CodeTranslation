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
int n;
int arr[200005];
int main(void){
	RI(n);
	REP(i,n) RI(arr[i]);
	if(n&1){
		for(int i=n-1;i>=0;i-=2) printf("%d ",arr[i]);
		for(int i=1;i<n;i+=2){
			printf("%d",arr[i]);
			if(i!=n-1&&i!=n-2) printf(" ");
		}
	} else {
		for(int i=n-1;i>=0;i-=2) printf("%d ",arr[i]);
		for(int i=0;i<n;i+=2){
			printf("%d",arr[i]);
			if(i!=n-1&&i!=n-2) printf(" ");
		}
	}
	
	puts("");
}