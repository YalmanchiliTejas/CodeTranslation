#include <iostream>

using namespace std;

int main(int argc, char** argv){
    int n;
    cin >> n;
    if(n == 0){
        cout << 0;
        return 0;
    }
    int mountains[n];
    for(int i = 0; i < n; i++){
        cin >> mountains[i];
    }
    int m = mountains[0];
    int total = 1;
    for(int i = 1; i < n; i++){
        if(mountains[i] >= m){
            total++;
            m = max(m, mountains[i]);
        }
    }
    cout << total;
    return 0;
}
