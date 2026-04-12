#include<cstdio>
#include<algorithm>
#include<vector>


using namespace std;

int main(void){


    int n;
    int s[128];
    while(scanf("%d", &n), n){
        int maxi = 0;
        int mini = 1000000000;
        int total=0, ns=0;

        for(int i = 0; i < n; i++){
            scanf("%d", &s[i]);
            if(s[i] > maxi){
                maxi = s[i];
            }
            if(s[i] < mini){
                mini = s[i];
            }
        }

        for(int i = 0; i < n; i++){
            if(maxi == s[i]){
                maxi = -1;
                continue;
            }
            if(mini == s[i]){
                mini = -1;
                continue;
            }
            total += s[i];
            ns++;
        }
        printf("%d\n", total/ns);
    }



    return 0;
}