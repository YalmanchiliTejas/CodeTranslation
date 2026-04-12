//6:20
#include <stdio.h>
#include <string.h>
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


char S[51];
int totalcnt[26];
int cnt[26];

int main(){
        int n;
        scanf("%d",&n);
        for(int i = 0; i < 26; i++) totalcnt[i] = 10000000;
        for(int i = 0; i < n; i++){
                scanf("%s",S);
                memset(cnt,0,sizeof(cnt));
                for(int j = 0; j < strlen(S); j++){
                        cnt[S[j]-'a']++;
                }
                for(int j = 0; j < 26; j++){
                        totalcnt[j] = min(totalcnt[j],cnt[j]);
                }
        }

        for(int i = 0; i < 26; i++){
                for(int j = 0; j < totalcnt[i]; j++) printf("%c",i+'a');
        }
        puts("");
}