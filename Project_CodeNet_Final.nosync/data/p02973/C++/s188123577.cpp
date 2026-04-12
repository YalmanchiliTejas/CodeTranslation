#include<bits/stdc++.h>
using namespace std;
int ara[100000];
vector<int> vec;
int main()
{
    int i,j,k;
    int n,color=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&ara[i]);
    color=1;
    vec.push_back(ara[n-1]);
    for(i=n-2;i>=0;i--){
        j=upper_bound(vec.begin(),vec.end(),ara[i])-vec.begin();
        if(j==vec.size()){
            color++;
            vec.push_back(ara[i]);
        }
        else
            vec[j]=ara[i];
    }
    printf("%d",color);
}
