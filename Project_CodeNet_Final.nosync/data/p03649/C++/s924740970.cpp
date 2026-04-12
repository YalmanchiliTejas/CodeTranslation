#include<cstdio>
#include<algorithm>
const long long inf = 1e17+7;
int a[55];
long long b[55];
//for good one
int vis[55];

int bruteForce(int n){
    int cnt = 0;
    while(true){
        //for(int i = 1; i <= n; i++) printf("%d ",a[i]);
        //printf("\n\n");
        int find = -1;
        for(int i = 1; i <= n; i++) if(find==-1 || a[i]>a[find]) find = i;
        if(a[find]<n) break;
        else{
            cnt++;
            for(int i = 1; i <= n; i++){
                if(i==find) a[i] -= n;
                else a[i]++;
            }
        }
    }
    return cnt;
}

long long max(long long a,long long b){ return a>b?a:b; }

long long min(long long a,long long b){ return a>b?b:a; }

int isGood(long long n){
    long long badMaxn = -1, goodMaxn = -1, goodMin = inf;
    for(int i = 1; i <= n; i++){
        if(vis[i]){
            goodMaxn = max(b[i],goodMaxn);
            goodMin = min(b[i],goodMin);
        }
        else{
            badMaxn = max(b[i],badMaxn);
        }
    }
    if(goodMin>n && (badMaxn==-1 || goodMin>=badMaxn+(long long)(n+1)) && (goodMaxn-goodMin)<(n+1ll)) return 1;
    else return 0;
}

void jump(long long n,long long& cnt){
    long long badMaxn = -1, goodMin = inf;
    long long goodCnt = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i]) goodMin = min(b[i],goodMin), goodCnt++;
        else badMaxn = max(b[i],badMaxn);
    }
    long long L = 1, R = inf;
    long long res = -1;
    while(L<=R){
        long long M = (L+R)/2;
        if((badMaxn==-1 || goodMin>=badMaxn+M*(n+1ll)) && goodMin>=n+(n-(goodCnt-1))*M){
            res = M;
           L = M+1;
        }
        else R = M-1;
    }
    cnt += res*goodCnt;
    for(int i = 1; i <= n; i++){
        if(vis[i]) b[i] -= (n-(goodCnt-1))*res;
        else b[i] += goodCnt*res;
    }
}

long long solve(int n){
    long long res = 0;
    while(true){
        //printf("seq: ");
        //for(int i = 1; i <= n; i++) printf("%lld ",b[i]);
        //printf("\n");
        //printf("cnt = %lld\n\n",res);
        int find = -1;
        for(int i = 1; i <= n; i++) if(find==-1 || b[i]>b[find]) find = i;
        if(b[find]<n) break;
        else{
            //printf("find = %d\n",find);
            res++;
            if(!vis[find]) vis[find] = 1;
            for(int i = 1; i <= n; i++){
                if(i==find) b[i] -= (long long)n;
                else b[i]++;
            }
            if(isGood(n)) jump(n,res);
        }
    }
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){ 
        scanf("%lld",&b[i]);
        //a[i] = b[i];
    }
    //printf("%d\n",bruteForce(n));
    printf("%lld\n",solve(n));
    return 0;
}
