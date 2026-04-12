#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    int n, i, tmp, sum_, max_, min_;
    while(true){
        scanf("%d", &n);
        if(n == 0) break;
        min_ = 1001;
        max_ = -1;
        sum_ = 0;
        for(i = 0; i < n; i++){
            scanf("%d", &tmp);
            sum_ += tmp;
            min_ = min(min_, tmp);
            max_ = max(max_, tmp);
        }
        sum_ = sum_ - max_ - min_;
        printf("%d\n", sum_/(n-2));
   }
}
