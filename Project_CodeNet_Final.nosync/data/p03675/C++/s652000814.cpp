#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,A[N],b=0;
list <int> L;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n+1;i++){
        scanf("%d",&A[i]);
    }
    for(int i=1;i<n+1;i++){
        if(b%2==0)
            L.push_back(A[i]);
        else
            L.push_front(A[i]);
        b++;
    }
    if(n%2==0){
        while(!L.empty()){
            printf("%d ",L.front());
            L.pop_front();
        }
        return 0;
    }
    while(!L.empty()){
        printf("%d ",L.back());
        L.pop_back();
    }
    return 0;
}
