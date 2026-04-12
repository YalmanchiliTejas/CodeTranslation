//6:48
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
ll max(ll a, ll b){return(a>b)?a:b;}
ll min(ll a, ll b){return(a<b)?a:b;}
ll abss(ll a){return(a<0)?-a:a;}

ll gcd(ll a, ll b){
        if(b > a){
                ll tmp = b;
                b = a;
                a = tmp;
        }
        if(b == 0) return a;
        else return gcd(b, a%b);
}
ll lcm(ll a, ll b){
        ll gcdi = gcd(a,b);
        return a/gcdi*(b);
}

int s[33];
int e[33];
int p[8];
int main(){
        ll N,M;
        scanf("%lld %lld",&N,&M);
        for(int i = 0; i < M; i++){
                scanf("%d %d",s+i,e+i);
        }


        for(int i = 0; i < N; i++){
                p[i] = i+1;
        }

        ll ans = 0;
        do{
                char ok = true;
                for(int i = 0; i < N-1; i++){
                        char found = false;
                        for(int j = 0; j < M; j++){
                                if((s[j] == p[i] && e[j] == p[i+1]) ||
                                   (e[j] == p[i] && s[j] == p[i+1]))
                                found = true;
                        }
                        if(!found){
                                ok = false;
                                break;
                        }
                }
                //for(int i = 0; i < N; i++){
                //      printf("%d,",p[i]);
                //}printf("ok=%d\n",ok);
                if(ok) ans++;
        }while(next_permutation(p+1,p+N));

        printf("%lld\n",ans);
}