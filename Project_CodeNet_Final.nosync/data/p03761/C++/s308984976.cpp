#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
char a[101][105],vis[101][105];
int n,m,len[105];
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%s",a[i]+1);
    for(int i=1; i<=n; i++) {
        len[i]=strlen(a[i]+1);
    }
    for(int I=1; I<=10000; I++) {
        bool bb=0;
        for(int J=1; J<=26; J++) {
            int t=J+'a'-1;
            bool b=1;
            for(int i=1; i<=n; i++) {
                bool cc=0;
                for(int j=1; j<=len[i]; j++) {
                    if(a[i][j]==t&&!vis[i][j]) {
                        cc=1;
                        break;
                    }
                }
                if(cc==0)b=0;
            }
            if(b) {
                bb=1;
                
                for(int i=1; i<=n; i++) {
                    for(int j=1; j<=len[i]; j++) {
                        if(a[i][j]==t&&!vis[i][j]) {
                        	vis[i][j]=1;
                            break;
                        }
                    }
                }
                printf("%c",t);
                break;
            }
        }
		if(!bb)break;
    }
    printf("\n");
    return 0;
}