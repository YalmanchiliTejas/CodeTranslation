#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <numeric>
#include <string>
#include <functional>

using namespace std;

int main(void){
    int N,K;
    string S;
    cin>>N>>S>>K;

    char c=S[K-1];
    for(int i=0;i<N;i++){
        if(S[i]!=c){
            S[i]='*';
        }
    }
    cout<<S<<endl;
    return 0;
}