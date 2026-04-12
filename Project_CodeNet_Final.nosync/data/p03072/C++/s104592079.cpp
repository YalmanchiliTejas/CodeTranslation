#include <cstdio>
using namespace std;
int main() {
    int n,cnt=0,Max=0,h;
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
        scanf("%d",&h);
        if(h>=Max) {
            cnt++;
            Max=h;
        }

    }
    printf("%d\n",cnt);
    return 0;
}
