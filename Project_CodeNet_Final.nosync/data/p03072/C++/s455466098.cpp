#include <iostream>

using namespace std;

int main(){
    int n, i, j, ver, maior;
    cin >> n;
    int h[128];
    ver=1;
    for(i=0;i<n;i++){
        cin >> h[i];
    }

    maior=h[0];
    for(i=1;i<n;i++){
        if(h[i]>=h[i-1] and h[i]>=maior){
            ver++;
            maior=h[i];
        }
    }

    cout << ver << endl;

    return 0;
}

