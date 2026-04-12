#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;
typedef long long ll;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
const int INF = 1<<29;

int main(){
    int N; cin >> N;
    string S; cin >> S;
    int K; cin >> K;
    
    for(int i=0;i<S.length();i++){
        if(i==K-1) continue;
        if(S[i]!=S[K-1]){
            S[i]='*';
        }
    }
    cout << S << endl;
    return 0;
}
