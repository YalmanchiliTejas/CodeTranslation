#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
using namespace std;

typedef long long ll;
const int MAX=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int d[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve(int n,char s[64][64]){
    int cnt[64][26]={0};
    for(int i=0;i<n;i++){
        for(int j=0;s[i][j];j++){
            char k=s[i][j];
            cnt[i][k-'a']++;
        }
    }
    for(int i=0;i<26;i++){
        int m=cnt[0][i];
        for(int j=1;j<n;j++){
            m=min(m,cnt[j][i]);
        }
        while(m--){
            printf("%c",i+'a');
        }
    }
    putchar('\n');
}

int main(){
    int n;
    char s[64][64];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    solve(n,s);
    return 0;
}
