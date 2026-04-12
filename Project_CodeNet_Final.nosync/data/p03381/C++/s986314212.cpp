#include<stdio.h>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int,int> PI;
int main(){
    int n;
    scanf("%d",&n);
    PI num[n];
    for(int i=0;i<n;i++){
        scanf("%d",&(num[i].first));
        num[i].second=i;
    }
    sort(num,num+n);
    int ans[n];
    for(int i=0;i<n;i++){
        if(i<n/2)ans[num[i].second]=num[n/2].first;
        else ans[num[i].second]=num[n/2-1].first;
    }
    for(int i=0;i<n;i++)printf("%d\n",ans[i]);
}
