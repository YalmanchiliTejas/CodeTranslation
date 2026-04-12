#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int m; scanf("%d", &m);
    while(m--){
        int ini, y, n; scanf("%d%d%d", &ini, &y, &n);

        int ans = 0;
        while(n--){
            int val = ini, type, due;
            double rate;
            scanf("%d%lf%d", &type, &rate, &due);
            if(type == 0){
                int interest = 0;
                for(int i=0;i<y;i++)interest += rate*val, val -= due;
                val += interest;
            }
            else{
                for(int i=0;i<y;i++) val*= 1 + rate, val -= due;
            }
            ans = max(ans, val);
        }
        printf("%d\n", ans);
    }
    return 0;
}