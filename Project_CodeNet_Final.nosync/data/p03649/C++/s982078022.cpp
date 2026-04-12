#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
typedef long long LL;
const int maxn = 55;
LL a[maxn];

int main(){
    while(cin >> N){
        for(int i = 1;i <= N;i++){
            scanf("%lld", &a[i]); 
        }
        LL ans = 0;
        while(true){
            bool flag = true;
            for(int i = 1;i <= N;i++){
                if(a[i] >= N){
                    flag = false;
                }
            }
            if(flag){
                break;
            }else{
                for(int i = 1;i <= N;i++){
                    if(a[i] >= N){
                        LL times = (a[i]) / N;
                        ans += times;
                        a[i] -= times * N;
                        for(int j = 1;j <= N;j++){
                            if(i != j){
                                a[j] += times;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
