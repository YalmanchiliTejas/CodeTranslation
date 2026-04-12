#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<numeric>
#include<algorithm>
#include<complex>
#include<queue>
#include<stdlib.h>
#define ll long long
#define for(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    int K;
    cin >> S;
    cin >> K;
    for(i,N){
        if(S[i]!=S[K-1]){
            S[i]='*';
        }
    }
    cout << S <<endl;
    return 0;
}
