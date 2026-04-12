#include<bits/stdc++.h>
using namespace std;

#define si(n) scanf("%d",&n)
#define MAX 200005

deque<int>d;
deque<int>::iterator it;

int arr[MAX],n;

int main()
{
    int i,j;
    bool flag=false;
    si(n);
    for(i=0;i<n;i++)
        si(arr[i]);
    for(i=0;i<n;i++){
        if(flag)d.push_back(arr[i]);
        else d.push_front(arr[i]);
        flag=!flag;
    }
    flag=!flag;
    if(flag){
        it=d.end();
        while(it != d.begin()){
            it--;
            printf("%d ",*it);
        }
    }
    else{
        it=d.begin();
        while(it != d.end()){
            printf("%d ",*it++);
        }
    }
    return 0;
}
