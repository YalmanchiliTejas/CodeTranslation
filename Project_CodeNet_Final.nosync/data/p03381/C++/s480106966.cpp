#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
struct No{
    int x;
    int id;
};
No a[maxn];

bool cmp(No a,No b)
{
    return a.x<b.x;
}

int main()
{
    int N;
    int x;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>a[i].x;
        a[i].id=i;
    }
    sort(a+1,a+1+N,cmp);
    int pos=N/2;

    int ans[maxn];
    for(int i=1;i<=N;i++){
        int id=a[i].id;
        if(i<=pos) ans[id]=a[pos+1].x;
        else ans[id]=a[pos].x;
    }
    for(int i=1;i<=N;i++)
        cout<<ans[i]<<endl;
    return 0;
}
