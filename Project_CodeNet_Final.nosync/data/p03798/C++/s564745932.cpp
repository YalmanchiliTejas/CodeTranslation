#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<complex>
#include<typeinfo>
using namespace std;

typedef unsigned long long ull;

bool sheepWolf(vector<bool> &input, bool first, bool second){
    int N = input.size() - 1 ;
    bool res[N+2];
    res[0] = first;
    res[1] = second;
    for (int i=1;i<N+1;i++){
        if(res[i]){
            if(input[i]){
                res[i+1] = res[i-1];
            }else{
                res[i+1] = !res[i-1];
            }
        }else{
            if(input[i]){
                res[i+1] = !res[i-1];
            }else{
                res[i+1] = res[i-1];
            }
        }
    }
    if (res[0] == res[N] && res[1] == res[N+1]){
        for (int i=0;i<N;i++){
            if(res[i]){
                cout << "S";
            }else{
                cout << "W";
            }
        }
        cout << endl;
        return true;
    }else{
        return false;
    }
}

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<bool> input(N);
    for (int i=0;i<N;i++){
        if(S[i] == 'o') input[i] = true;
        if(S[i] == 'x') input[i] = false;
    }
    input.push_back(input[0]);
    if(!sheepWolf(input, true, true)){
        if(!sheepWolf(input, true, false)){
            if(!sheepWolf(input, false, true)){
                if(!sheepWolf(input, false, false))
                    cout << -1 << endl;
            }
        }
    }
    return 0;
}