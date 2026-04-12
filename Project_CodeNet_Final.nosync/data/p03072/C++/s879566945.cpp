#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    scanf("%d",&n);
    int mx = INT_MIN,counter =0;
    while(n--){
        int temp;
        scanf("%d",&temp);
        if(mx<=temp){
            mx = temp;
            counter++;
        }
    }
    printf("%d\n",counter);
    return 0;
}
