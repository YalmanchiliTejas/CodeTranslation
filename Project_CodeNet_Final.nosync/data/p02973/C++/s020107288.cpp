#include<bits/stdc++.h>
using namespace std;
inline int readuint(){
    char x;int r=0;
    while(1){x=getchar();if(x>' ')break;}
    while(1){
        r=r*10+x-'0';
        x=getchar();
        if(!isdigit(x))break;
    }
    return r;
}

const int maxn=1e5+9;
int n;
int a[maxn],s[maxn];
int init(){
    n=readuint();
    for(int i=0;i<n;++i)a[i]=readuint();
}

int solve(){
    for(int i=0;i<n;++i)s[i]=-1;
    int c=0;
    for(int i=0;i<n;++i){
        int p=lower_bound(s,s+n,a[i])-s-1;
        if(s[p]==-1)c++;
        s[p]=a[i];
    }
    return c;
}
int main(){
	init();
	cout<<solve()<<endl;
    return 0;
}
