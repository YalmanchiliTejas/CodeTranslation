#include<bits/stdc++.h>
#define ULL unsigned long long
#define LL long long
#define Max 100005
#define mem(a,b) memset(a,b,sizeof(a));
#define pb push_back
#define mp make_pair
const LL mod=1e9+7;
const ULL base=131;
const LL LL_MAX=9223372036854775807;
using namespace std;
multiset<LL>s;
LL a[Max];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n;i++){
        if(!s.size() || a[i]<=*s.begin()){
            s.insert(a[i]);
        }else{
            multiset<LL>::iterator t=s.lower_bound(a[i]);
            t--;
            s.erase(t);
            s.insert(a[i]);
        }
    }
    printf("%d\n",s.size());
    return 0;
}

