#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long n,x,m;
    scanf("%ld %ld %ld", &n, &x, &m);
    vector<long> viNum(m, -1);
    long nAns = 0;
    long aTmp = x;
    
    if(n <= m){
        for(long i = 0; i < n; i++){
            nAns += aTmp;
            aTmp = aTmp * aTmp;
            aTmp %= m;
        }
        printf("%ld", nAns);
        return 0;
    }
    
    long nSum = 0;
    int iLoop = 0;
    int iStart = 0;
    for(long i = 0; i < m; i++){
        nSum += aTmp; //1~i+1まで
        if(viNum[aTmp] == -1){
            viNum[aTmp] = i;
            aTmp = aTmp * aTmp;
            aTmp %= m;
            continue;
        } else {
            iLoop = i - viNum[aTmp];
            iStart = i;
            break;
        }        
    }

    long iLoopCount = (n-iStart-1) / iLoop;
    long iRemain = (n-iStart-1) % iLoop;
    long iLoopSum = 0;
    long iRemainSum = 0;
    for(long i = 0; i < iLoop; i++){
        aTmp = aTmp * aTmp;
        aTmp %= m;
        iLoopSum += aTmp;
        if(i == iRemain - 1){
            iRemainSum = iLoopSum;
        }
    }
    
    printf("%ld", nSum + iLoopSum * iLoopCount + iRemainSum);
    return 0;
}
