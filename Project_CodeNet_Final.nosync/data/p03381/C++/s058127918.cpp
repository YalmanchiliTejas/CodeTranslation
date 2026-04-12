#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> same,sorted;
int main()
{
    int N,x,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&x);
        same.push_back(x);
        sorted.push_back(x);
    }
    sort(sorted.begin(),sorted.end());
    int med=sorted[N/2];
    for(i=0;i<N;i++)
    {
        if(same[i]<med) printf("%d\n",med);
        else printf("%d\n",sorted[N/2-1]);
    }
}
