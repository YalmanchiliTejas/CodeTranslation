#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
int ax[200005];
list<int> l;

int main()
{
    int n,i,a;
    bool flag = 1;
    list<int>::iterator p;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&ax[i]);
    }
    for(i=0;i<n;i++){
        if(flag)l.push_front(ax[i]);
        else l.push_back(ax[i]);
        flag = !flag;
    }
    if(!flag){
        for(p=l.begin();p!=l.end();p++)printf("%d ",*p);
    }
    else{
        for(p=l.end();p!=l.begin();)printf("%d ",*(--p));
    }
    return 0;
}
