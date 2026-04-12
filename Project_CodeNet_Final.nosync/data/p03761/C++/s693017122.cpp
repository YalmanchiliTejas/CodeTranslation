#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int vis[66][66];
int ans[66];
char s[66];
int n;
int _min(int x,int y){
        if(x < y) return x;
        else return y;
}
int main(){
        while(scanf("%d",&n) != EOF){

                for(int i = 0;i < n;++i){
                        scanf("%s",s);
                        for(int j = 0;s[j];++j){
                                vis[i][ s[j] - 'a' ] ++;
                        }
                }
                for(int i = 0;i < 26;++i) ans[i] = 999;
                for(int i = 0;i < 26;++i){
                        for(int j = 0;j < n;++j){
                                ans[i] = _min(ans[i],vis[j][i]);
                        }
                }
                for(int i = 0;i < 26;++i){
                        while(ans[i]--){
                                printf("%c",i+'a');
                        }
                }
                printf("\n");
        }
        return 0;
}
