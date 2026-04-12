#include <stdio.h>
#include <map>
#include <utility>
using namespace std;
typedef pair<int,int> pi;
#define F first
#define S second
#define MP make_pair
int main(){
    int n,ans=0;
    long long int now=0,temp;
    map<long long int,int> m;
    scanf("%d",&n);
    m.insert(MP(0,-1));
    for(int i=0;i<n;i++){
        scanf("%lld",&temp);
        now+=temp;
        if(m.find(now)==m.end())m.insert(MP(now,i));
        else ans=max(ans,i-m[now]);
    }
    printf("%d\n",ans);
}

