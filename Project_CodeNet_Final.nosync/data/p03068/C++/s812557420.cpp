#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
//typedef pair<int,int> P;
//priority_queue<int> pque;
//priority_queue<int, vector<int>, greater<int>> pque;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 1000000000;//10^9
ll MOD  = 998244353;



int main(void){
    int N,K;
    string S;
    cin >> N >> S >> K;
    char a;
    a = S.at(K-1);
    
    
    for(int i = 0; i < N; i++){
        if(S.at(i) == a){
            cout << a;
        }
        else{
            cout << '*';
        }
    }
    cout << endl;
}
