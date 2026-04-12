#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
const int N=10,INF=0x3f3f3f3f;
long long k,a,b;
int main()
{
    while(~scanf("%lld%lld%lld",&k,&a,&b)){
        if(a<=b){
            if(a<k) printf("-1\n");
            else printf("1\n");
        }
        else {
            if(a>=k){
                printf("1\n");
            }
            else {
                long long sum=k/(a-b);
                while(sum*(a-b)+a>k){
                        sum--;
                }
                while(sum*(a-b)+a<k){
                        sum++;
                }
                    printf("%lld\n",sum*2+1);


            }
        }


    }
    return 0;
}
