#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n),n){
        int go[100001];
        for(int i = 0; i < n; i++){
            scanf("%d",&go[i]);
        }
        int con[100001]={0};
        con[0] = 1;
        for(int i = 1; i < n ; i++){
            if(i % 2 == 0){
                if(go[i-1] == go[i])con[i] = con[i-1]+1;
                else con[i] = 1;
            }
            else{
                if(go[i-1] == go[i])con[i] = con[i-1]+1;
                else{
                    int add = i-1-con[i-1];
                    int color = (go[i-1]==0)?1:0;
                    for(int j = i-1; j > i-1-con[i-1]; j--){
                        go[j] = color;
                    }
                    con[i] = con[i-1]+1+con[add];
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++)if(go[i] == 0)cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}