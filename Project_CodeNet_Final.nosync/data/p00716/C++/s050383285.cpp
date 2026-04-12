#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{

    int m;
    scanf(" %d", &m);
    for(int i = 0; i < m; i++){
        int syoki;
        scanf(" %d", &syoki);
        int y;
        scanf(" %d", &y);
        int n;
        scanf("%d", &n);
        int syurui, tesuu;
        double nenri;
        int ma = 0;
        for(int j = 0; j < n; j++){
            scanf(" %d %lf %d", &syurui, &nenri, &tesuu);

            // main
            if(syurui == 1){
                int a = syoki, b;
                for(int k = 0; k < y; k++){
                    b = a * nenri;
                    a = a + b - tesuu;
                }
                ma = max(ma, a);
           //     printf("\t -->: %d", a);
            } else if(syurui == 0){
                int a = syoki, b, d = 0;
                for(int k = 0; k < y; k++){
                    b = a * nenri;
                    a = a - tesuu;
                    d += b;
                }
             //   printf("\t -->: %d", a + d);
                ma = max(ma, a + d);
            }
        }
        printf("%d\n", ma);
    }
    return 0;
}