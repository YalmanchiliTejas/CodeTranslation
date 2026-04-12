#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    int N,K;
    string S;
    cin >> N >> S; cin >> K;
    for(int i=1;i<=N;i++){
        if(i==K) continue;
        else{
            if(S[i-1]!=S[K-1]) S[i-1]='*';
        }
    }
    cout << S << endl;
}