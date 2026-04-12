#include <cstdio>
#include <iostream>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)


int main(){
        int N;
        scanf("%d",&N);
        long long int a[N];
        rep(i,N){
                scanf("%lld",a+i);
        }
        long long int ans = 0;
        for(;;){
                int cl = 0;
                rep(i,N){
                        if (a[i]>=N){
                                cl = 1;
                                long long int n = (a[i]-a[i]%N)/N;
                                rep(j,N){
                                        if (i!=j){
                                                a[j] += n;
                                        }
                                }
                                ans += n;
                                a[i] = a[i] % N;
                        }
                }
                if (cl == 0){
                        break;
                }
        }
        printf ("%lld\n",ans);
        return 0;
}
