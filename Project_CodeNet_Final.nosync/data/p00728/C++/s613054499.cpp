#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    for(;;){
        scanf("%d",&n);
        if(n==0) break;
        vector<int> ar(n);
        for(int &x : ar){
            scanf("%d",&x);
        }
        sort(ar.begin(),ar.end());
        int sum=0;
        for(int i=1;i<n-1;i++){
            sum+=ar[i];
        }
        printf("%d\n",sum/(n-2));
    }
}