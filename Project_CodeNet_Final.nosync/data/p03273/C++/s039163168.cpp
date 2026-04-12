#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<string.h>
#include<iostream>
#include<algorithm>
#define PI acos(-1.0)
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=3e5+5;
const int MOD=1e9+7;
template <class T>
bool sf(T &ret){ //Faster Input
    char c; int sgn; T bit=0.1;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&c!='.'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    if(c==' '||c=='\n'){ ret*=sgn; return 1; }
    while(c=getchar(),c>='0'&&c<='9') ret+=(c-'0')*bit,bit/=10;
    ret*=sgn;
    return 1;
}
int sign(int x){
    return abs(x)<1e-7?0:x<0?-1:1;
}
char mp[200][200];
map<int,int> t,y;
int main(void){
    ll n,m;
    cin >>n>>m;
    for(int i=1;i<=n;i++)    cin >> mp[i]+1;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='.')   cnt++;
        }
        if(cnt==m)  t[i]=1;
    }
    for(int i=1;i<=m;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(mp[j][i]=='.')   cnt++;
        }
        if(cnt==n)  y[i]=1;
    }
//    cout <<"~"<<mp[4]<<endl;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=m;j++){
            if(t[i]||y[j])    continue;
            printf("%c",mp[i][j]);
            cnt++;
        }
        if(!cnt)    continue;
        printf("\n");
    }

    return 0;

}
