#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
template<class Read>void in(Read &x){
    x=0;
    int f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        f|=(ch=='-');
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    x=f?-x:x;
    return;
}
const int d[10][10]={{1,1},{1,-1},{-1,1},{-1,-1}};
int n,a[100005];
char s[100005];
bool check(){
    for(int i=1;i<=n;i++){
        int l=(i==1?n:i-1);
        int r=(i==n?1:i+1);
        if(s[i]=='o'){
            if(a[i]==1&&a[l]!=a[r])return 0;
            if(a[i]==-1&&a[l]==a[r])return 0;
        }
        else{
            if(a[i]==1&&a[l]==a[r])return 0;
            if(a[i]==-1&&a[l]!=a[r])return 0;
        }
    }
    return 1;
}
int main(){
	in(n);
    scanf("%s",s+1);
    for(int ca=0;ca<4;ca++){
        a[1]=d[ca][0];
        a[2]=d[ca][1];
        for(int i=2;i<n;i++){
            if(a[i]==1)a[i+1]=(s[i]=='o'?a[i-1]:-a[i-1]);
            else a[i+1]=(s[i]=='x'?a[i-1]:-a[i-1]);
        }
        if(check()){
            for(int i=1;i<=n;i++)putchar((a[i]==1?'S':'W'));
            puts("");
            return 0;
        }
    }
    puts("-1");
	return 0;
}
