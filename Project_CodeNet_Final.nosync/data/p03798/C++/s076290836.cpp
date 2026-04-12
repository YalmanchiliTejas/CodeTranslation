#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[100005];
char s[100005];
int n;
int main(){
    scanf("%d%s",&n,s+1);
    int flag;
    for(int i=1;i<=2;i++){
        a[1]=i;
        for(int j=1;j<=2;j++){
            a[2]=j;
            flag=1;
            if(a[1]==1){
                if(s[1]=='o') a[n]=j;
                else a[n]=j%2+1;
            }
            else{
                if(s[1]=='x') a[n]=j;
                else a[n]=j%2+1;
            }
            for(int k=2;k<n-1;k++){
                if(a[k]==1){
                    if(s[k]=='o') a[k+1]=a[k-1];
                    else a[k+1]=a[k-1]%2+1;
                }
                else{
                    if(s[k]=='x') a[k+1]=a[k-1];
                    else a[k+1]=a[k-1]%2+1;
                }
            }
            int last;
            if(a[n-1]==1){
                if(s[n-1]=='o') last=a[n-2];
                else last=a[n-2]%2+1;
            }
            else{
                if(s[n-1]=='x') last=a[n-2];
                else last=a[n-2]%2+1;
            }
            if(last!=a[n]){
                flag=0;
            }
            if(a[n]==1){
                if(s[n]=='o')
                    if(a[1]!=a[n-1]) flag=0;
                if(s[n]=='x')
                    if(a[1]==a[n-1]) flag=0;
            }
            else{
                if(s[n]=='x')
                    if(a[1]!=a[n-1]) flag=0;
                if(s[n]=='o')
                    if(a[1]==a[n-1]) flag=0;
            }
            if(flag) break;
        }
        if(flag) break;
    }
    if(flag){
        for(int i=1;i<=n;i++){
            if(a[i]==1) printf("S");
            else printf("W");
        }
        printf("\n");
    }
    else printf("-1\n");
}
