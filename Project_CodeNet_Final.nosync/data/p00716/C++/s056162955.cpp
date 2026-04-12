#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while (T--){
        int s, y, n;
        
        scanf("%d %d %d", &s, &y, &n);
        
        int ans = s;
        
        for (int i = 0; i < n; i++){
            int t, dec;
            double r;
            
            scanf("%d %lf %d", &t, &r, &dec);
            if (t == 0){
                int tmp = s, tmp2 = 0;
                for (int j = 0; j < y; j++){
                    tmp2 += tmp * r;
                    tmp -= dec;
                }
                ans = max(ans, tmp + tmp2);
            }
            else {
                int tmp = s;
                for (int j = 0; j < y; j++){
                    tmp *= (1 + r);
                    tmp -= dec;
                }
                ans = max(ans, tmp);
            }
        }
        
        printf("%d\n", ans);
    }
    
    return (0);
}