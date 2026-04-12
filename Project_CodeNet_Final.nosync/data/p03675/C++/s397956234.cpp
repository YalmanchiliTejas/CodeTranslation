#include <cstdio>
#include <queue>

using namespace std;

const int N = 2e5 + 500;

int n;
int a[N],b[N];
deque < int > v;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        scanf("%d",a+i);
    int rotat = 0;
    for(int i = 0;i<n;i++){
        if(rotat) v.push_back(a[i]);
        else v.push_front(a[i]);
        rotat = 1 - rotat;
    }
    while(v.size() > 0){
        if(rotat)printf("%d ",v.front());
        else printf("%d ",v.back());
        if(rotat) v.pop_front();
        else      v.pop_back();
    }
    printf("\n");
}
