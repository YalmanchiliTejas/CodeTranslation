#include <bits/stdc++.h>

using namespace std;

#define si(a) scanf("%d",&a)

deque<int> Q;

int main()
{
    int i,n,x;
    si(n);
    for(i=0;i<n;i++){
        si(x);
        if(i%2)Q.push_back(x);
        else Q.push_front(x);
    }
    if(n%2==0){
        for(i=0;i<n;i++){
            if(i)printf(" ");
            printf("%d",Q.back());
            Q.pop_back();
        }
        printf("\n");
    }
    else{
        for(i=0;i<n;i++){
            if(i)printf(" ");
            printf("%d",Q.front());
            Q.pop_front();
        }
        printf("\n");
    }
    return 0;
}
