#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define lson rt<<1
#define rson rt<<1|1
#define pb push_back
#define fi first
#define se second
#define what_is(x) cerr<<#x<<" "<<x<<endl;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
/*********head**********/
const int MAXN=105;
char buf[MAXN];
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",buf+1);
    int k;
    scanf("%d",&k);
    rep(i,1,n){
        if(buf[i]!=buf[k]){
            buf[i]='*';
        }
    }
    puts(buf+1);
    return 0;
}
