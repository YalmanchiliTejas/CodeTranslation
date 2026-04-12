#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long N;
    long long X, M;
    cin >> N >> X >> M;
    
    vector<long long> vec;
    long long a = X;
    long long cycleStart = N - 1, cycleEnd = N - 1;
    
    long long answer = 0;
    for (long long i = 0; i < N; i++) {
        vec.push_back(a);
        a = (long long)pow(a, 2) % M;
        answer += vec[i];
        
        vector<long long>::iterator itr = find(vec.begin(), vec.end(), a);
        if (itr != vec.end()){
            cycleStart = distance(vec.begin(), itr);
            cycleEnd = i;
            break;
        }
        
    }
    
    
    long long cycle = cycleEnd - cycleStart + 1;
    long long numCycle = (N - cycleStart) / cycle - 1;
    long long res = (N - cycleStart) % cycle;
    
    if (numCycle > 0) {
        for (long long i = cycleStart; i <= cycleEnd; i++) {
            if (i < cycleStart + res){
                answer += vec[i] * (numCycle + 1);
            } else {
                answer += vec[i] * numCycle;
            }
        }
    }
    
    cout << answer;

}
