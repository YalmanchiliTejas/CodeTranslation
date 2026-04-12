#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    int a=0;
    int b=0;
    for (int i=0;i<N;i++){
        cin >> H.at(i);
        if (a<=H.at(i)){
            a=H.at(i);
            b=b+1;
        }
    }
    cout << b << endl;
    
}