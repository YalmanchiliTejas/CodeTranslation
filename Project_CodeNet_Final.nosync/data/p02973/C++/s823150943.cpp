#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std ;
const int maxn=1e5+10;
int n,cnt=0;
int arr[maxn];
multiset<int>s;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++){
        auto p=s.lower_bound(arr[i]);
        if(p!=s.begin()){
            p--;
            s.erase(p);
        }
        s.insert(arr[i]);
    }
    printf("%d\n",s.size());
}
