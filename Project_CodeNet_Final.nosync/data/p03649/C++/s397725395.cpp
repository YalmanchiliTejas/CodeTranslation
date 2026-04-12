#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long n;
    scanf("%ld", &n);
    vector<long> viNum(n);
    for(long i = 0; i < n; i++){
        scanf("%ld", &viNum[i]);
    }
    sort(viNum.rbegin(), viNum.rend());
    long nAns = 0;
    if(viNum[0] < n * n){
        while(viNum[0] >= n){
            viNum[0] -= n;
            for(long i = 1; i < n; i++){
                 viNum[i]++;
            }
            sort(viNum.rbegin(), viNum.rend());
            nAns++;
        }
        printf("%ld", nAns);
        return 0;
    }
    
    vector<long> viRema(n);
    for(long i = 0; i < n; i++){
        viRema[i] = viNum[i] % (n + 1);
    }
    sort(viRema.rbegin(), viRema.rend());
    
    long iMinOfMax = n;
    long iMin = 0;
    long nSum = 0;
    for(long i = 0; i < n; i++){
        viRema[0] -= n;
        for(long i = 1; i < n; i++){
             viRema[i]++;
        }
        sort(viRema.rbegin(), viRema.rend());
        if(viRema[0] < iMinOfMax){
            iMinOfMax = viRema[0];
            nSum = 0;
            for(long i = 0; i < n; i++){
                nSum += viRema[i];
            }
        }
    }
    nSum += (n - 1 - iMinOfMax) * n;
    for(long i = 0; i < n; i++){
        nAns += viNum[i];
    }
    nAns -= nSum;
    printf("%ld", nAns);
    
    return 0;
}
