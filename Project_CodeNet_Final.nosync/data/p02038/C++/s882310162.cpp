#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    char P[100000];
    cin >> N;
    for(int i=0; i<N; i++) cin >> P[i];
    char c = P[0];
    for(int i=1; i<N; i++){
        if(c == 'T' && P[i] == 'F'){
            c = 'F';
        }else{
            c = 'T';
        }
    }
    cout << c << endl;
}

