#include <bits/stdc++.h>
using namespace std;

char m(char a, char b){
    if(a == 'T' and b == 'F') return 'F';
    else return 'T';
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<char> C(n);
    for(int i = 0; i < n; i++){
        cin >> C[i];
    }

    char bef = m(C[0], C[1]);
    for(int i = 2; i < n; i++){
        bef = m(bef, C[i]);
    }

    cout << bef << endl;


    return 0;
}
