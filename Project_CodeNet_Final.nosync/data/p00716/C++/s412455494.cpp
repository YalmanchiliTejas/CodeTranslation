#include<cstdio>
#include<cmath>
#include<algorithm>
#define REP(i,a,n) for(int i = a;i < n;i++)
#define rep(i,n) REP(i,0,n)
using namespace std;
int in_i(){int n;scanf("%d",&n);return n;}
double in_d(){double n;scanf("%lf",&n);return n;}
int main(void){
    int n = in_i();
    rep(i,n){
        int s = in_i(),year = in_i(),m = in_i();
        long long int ma = 0;
        rep(j,m){
            int type = in_i();
            double p = in_d();
            int tax = in_i();
            long long int money = s,t = 0;
            if(type == 0){
                rep(k,year){
                    t += (long long int)(money*p);
                    money -= (long long int)tax;
                }
            }
            else{
                rep(k,year){
                    money += (long long int)(money*p);
                    money -= (long long int)tax;
                }
            }
            ma = max(ma,money+t);
        }
        printf("%lld\n",ma);
    }
    return 0;
}