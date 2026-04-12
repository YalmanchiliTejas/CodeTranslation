#include<bits/stdc++.h>

using namespace std;

#define lint long long

vector<pair<lint, lint>> List(51);
lint num(lint i, lint N){
    if(N == 0){
        if(i == 0){
            return 0;
        } else {
            return 1;
        }
    }
    else if(i >= List[N - 1].first + 2){
        return List[N - 1].second + 1 + num(i - List[N - 1].first - 2, N - 1);
    } else if(i == 1 | i == 0){
        return 0;
    } else {
        return num(i - 1, N - 1);
    }
}


int main(){
    lint N, X;
    cin >> N >> X;
    
    lint l = 1;
    lint p = 1;
    
    for(int i = 0; i < 50; ++i){
        List[i] = make_pair(l, p);
        l = 2 * l + 3;
        p = 2 * p + 1;
    }
    
    cout << num(X, N) << endl;
    
}