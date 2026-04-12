#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int h[n];
    for(int i=0; i<n; i++){
        cin >> h[i];
    }

    int total=0;
    int max=-1;
    for(int i=0; i<n; i++){
        if(max<=h[i]){
            max=h[i];
            total++;
        }
    }

    cout << total << endl;
    return 0;
}