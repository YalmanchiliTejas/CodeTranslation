#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
int h[25];

int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=0;j<i;j++){
            if(h[j]>h[i]){
                flag=true;
            }
        }
        if(!flag){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}



