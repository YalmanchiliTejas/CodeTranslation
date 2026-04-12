#include<cstdio>

int min(int a,int b){ return a>b?b:a; }

//i%mod = [0,k]
int getNumber(int l,int r,int mod,int k){
    if(k<0) return 0;
    int res = 0;
    int cur = l%mod;
    if(cur<=k){ 
        int upGrade = min(l+k-cur,r);
        res += upGrade-l+1;
    }
    l = l-cur+mod;
    if(l>r) return res;
    res += (r-l+1)/mod*(k+1);
    l += (r-l+1)/mod*mod;
    if(l>r) return res;
    int upGrade = min(l+k,r);
    res += upGrade-l+1;
    return res;
}

int bfSolve(int n,int k){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) if((i%j)>=k) ans++;
    }
    return ans;
}

int main(){
    /*int x = -1, y = -1;
    for(int n = 3; n <= 3; n++){
        for(int k = 1; k <= 1; k++){
            long long ans = 0;
            for(int i = k+1; i <= n; i++){
                int add = n-getNumber(1,n,i,k-1);
                printf("i = %d: %d\n",i,add);
                ans += (long long)add;
            }
            int bfRes = bfSolve(n,k);
            printf("%d %lld\n",bfRes,ans);
        }
    }
    printf("x = %d, y = %d\n",x,y);
    printf("%d\n",getNumber(1,3,2,0));*/
    int n,k;
    scanf("%d%d",&n,&k);
    long long ans = 0;
    for(int i = k+1; i <= n; i++){
        int add = n-getNumber(1,n,i,k-1);
        ans += (long long)add;
    }
    printf("%lld\n",ans);
    return 0;
}
