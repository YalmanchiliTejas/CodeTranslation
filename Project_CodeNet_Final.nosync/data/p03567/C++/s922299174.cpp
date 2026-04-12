#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int read(){
    char c;int s=0,t=1;
    while(!isdigit(c=getchar()))if(c=='-')t=-1;
    do{s=s*10+c-'0';}while(isdigit(c=getchar()));
    return s*t;
}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a<b?b:a;}
int abs(int x){return x>0?x:-x;}
void mins(int &a,int b){if(a>b)a=b;}
void maxs(int &a,int b){if(a<b)a=b;}
//void insert(int u,int v){tot++;e[tot].v=v;e[tot].from=first[u];first[u]=tot;}
/*------------------------------------------------------------*/
const int inf=0x3f3f3f3f;

int n;
char s[10];
int main(){
    scanf("%s",s);
    int n=strlen(s);
    bool ok=0;
    for(int i=0;i<n-1;i++)if(s[i]=='A'&&s[i+1]=='C'){ok=1;break;}
    if(ok)printf("Yes");else printf("No");
    
    return 0;
}