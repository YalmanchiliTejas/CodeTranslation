#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll N, X, M;
    cin >> N >> X >> M;

    ll sumList[M + 1];
    ll firstAppearedNum[M + 1];
    rep(i, M + 1){
        sumList[i] = 0;
        firstAppearedNum[i] = -1;
    }
    ll counter = 1;
    ll sum = 0;
    while(firstAppearedNum[X] == -1 & counter <= N){
        firstAppearedNum[X] = counter;
        sum += X;
        sumList[counter] = sum;
        X = X * X % M;//cout << "a: " << X << ", sum: " << sum << endl;
        counter++;
    }
    ll loopSize;
    if(firstAppearedNum[X] == -1){
        loopSize = counter - 1;
    }else{
        loopSize = counter - firstAppearedNum[X];
    }//cout << "aaa" << counter - loopSize - 1 << endl;
    
    ll ans = 0;
    ans += sumList[counter - loopSize - 1];//cout << "ans1: " << ans << endl;
    ans += (sumList[counter - 1] - sumList[counter - loopSize - 1]) * ((N - (counter - loopSize - 1)) / loopSize);//cout << "ans2: " << ans <<endl;
    ans += sumList[(N - (counter - loopSize - 1)) % loopSize + (counter - loopSize - 1)] - sumList[counter - loopSize - 1];//cout << "ans3: " << ans << endl;

    cout << ans << endl;

    return 0;
}
