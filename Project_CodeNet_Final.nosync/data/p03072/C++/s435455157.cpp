#include <bits/stdc++.h>
using namespace std;
int N;
int Height[100];
int memo = -1;
int kai = 0;
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> Height[i];
    }
    for(int i=0;i<N;i++){
        if(memo <= Height[i]){
            kai += 1;
            memo = Height[i];
        }
    }
    cout << kai << endl;
}