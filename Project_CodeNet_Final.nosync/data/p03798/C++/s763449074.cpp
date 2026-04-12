#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<sstream>
#include<functional>
#define D long long
#define F double
#define MAX 0x7fffffff
#define MIN -0x7fffffff
#define mmm(a,b) memset(a,b,sizeof(a))
#define for1(i,a,b) for(int i=a;i<=b;i++)
#define for2(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
#define N 60100
#define MOD ((int)1e9+7)
#define mod ((int)1e9+7)
typedef long long ll;
const double pi=acos(-1);
const F eps=1e-6;
D read(){ D ans=0; char last=' ',ch=getchar();
while(ch<'0' || ch>'9')last=ch,ch=getchar();
while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
if(last=='-')ans=-ans; return ans;
}


int f[2000009];//1Ст -1АЗ
int n;
int ok;
string x;
void fin(int l,int r){
    if(ok==1)return;
    mmm(f,0);
    f[1]=l,f[n]=r;
    if(f[1]==1){
        if(x[1]=='o')f[2]=f[n]*1;
        else f[2]=f[n]*(-1);
    }
    else{
        if(x[1]=='x')f[2]=f[n]*1;
        else f[2]=f[n]*(-1);
    }
    int ar=1;
    while(1){
        ar++;if(ar==n-1)break;
        if(f[ar]==1){
            if(x[ar]=='o')f[ar+1]=f[ar-1]*1;
            else f[ar+1]=f[ar-1]*(-1);
        }
        else{
            if(x[ar]=='x')f[ar+1]=f[ar-1]*1;
            else f[ar+1]=f[ar-1]*(-1);
        }
    }
    if(f[n-1]==1){
        if(x[n-1]=='o'){
            if(f[n-2]!=f[n])return;
        }
        else{
            if(f[n-2]==f[n])return;
        }
    }
    else{
        if(x[n-1]=='x'){
            if(f[n-2]!=f[n])return;
        }
        else{
            if(f[n-2]==f[n])return;
        }
    }

    if(f[n]==1){
        if(x[n]=='o'){
            if(f[n-1]!=f[1])return;
        }
        else{
            if(f[n-1]==f[1])return;
        }
    }
    else{
        if(x[n]=='x'){
            if(f[n-1]!=f[1])return;
        }
        else{
            if(f[n-1]==f[1])return;
        }
    }
    ok=1;return;
}

int  main(){
    cin>>n>>x;x=' '+x;
    ok=0;
    fin(1,1);
    fin(-1,1);
    fin(-1,-1);
    fin(1,-1);
    if(ok==0)printf("%d\n",-1);
    else{
        for(int i=1;i<=n;i++){
            if(f[i]==1)printf("S");
            else printf("W");
        }
        printf("\n");
    }
    return 0;
}
/*
oxxxooxxox
SSWSSSSWSW*/


