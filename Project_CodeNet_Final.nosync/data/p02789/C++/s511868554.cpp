#include <bits/stdc++.h>
using namespace std;

void ansFlg(int x, int y){
    if(x == y){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
int main(){
    int N,M;
    cin >> N >> M;
    ansFlg(N, M);
}