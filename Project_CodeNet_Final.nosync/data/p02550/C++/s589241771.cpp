#include <iostream>
#include <vector>
using namespace std;

int main(void){
    long long N;
    int X, M;
    cin >> N >> X >> M;
    vector<long long> PowerX;
    vector<int> Loop(M, -1);
    long long powerXbuf = X;
    int loopstart, looplength;
    for(int i=0; i<=M; i++){
        PowerX.push_back(powerXbuf);
        Loop[powerXbuf] = i;
        powerXbuf *= powerXbuf;
        powerXbuf %= M;
        if(Loop[powerXbuf] != -1){
            loopstart = Loop[powerXbuf];
            looplength = i-loopstart+1;
            break;
        }
    }
    long long numLoop = (N-loopstart) / looplength;
    long long numSurplus = (N-loopstart) % looplength;
    long long res = 0;
    if(loopstart > N){
        for(int i=0; i<N; i++){
            res += PowerX[i];
        }
    }else{
        for(int i=0; i<M; i++){
            if(i >= N)break;
            if(i > loopstart + looplength)break;
            if(i < loopstart){
                res += PowerX[i];
            }else if(i < loopstart + numSurplus){
                res += PowerX[i] * (numLoop + 1);
            }else{
                res += PowerX[i] * numLoop;
            }
        }
    }
    cout << res << endl;
    return 0;
}